
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <fstream>
#include <iostream>

__global__ void manipulateArray(long* indexArray, long from, long amount)
{
    long i = threadIdx.x;

    indexArray[from + i] += amount;
}

struct inputQueryRow
{
    long rangeMin, rangeMax, amount;
};

struct input
{
    long indexArrayCount, queryCount;
    struct inputQueryRow* inputQueryRow;
};



long maxSum(struct input* inputData)
{
    long* indexArray = (long*)malloc(inputData->indexArrayCount * sizeof(long));
    memset(indexArray, 0, inputData->indexArrayCount * sizeof(long));
    
    cudaError_t cudaStatus;
    cudaStatus = cudaSetDevice(0);


    //! create memory space for indexArray in GPU.
    long* devGPUMemory = 0;
    cudaStatus = cudaMalloc( (void**)&devGPUMemory, inputData->indexArrayCount * sizeof(long) );
    cudaStatus = cudaMemcpy(devGPUMemory, indexArray, inputData->indexArrayCount * sizeof(long), cudaMemcpyHostToDevice);

    for (long i = 0; i < inputData->queryCount; i++)
    {
        long rangeMin = inputData->inputQueryRow[i].rangeMin;
        long rangeMax = inputData->inputQueryRow[i].rangeMax;
        long amount = inputData->inputQueryRow[i].amount;


        int curThreads = 0;
        int curCursor = 0;

        int rangeSize = rangeMax - rangeMin;

        for (int j = rangeMin - 1; j < rangeMax; j += 1024)
        {
            curCursor = j;
            curThreads = (j + 1024) > rangeMax ? rangeMax - j : 1024;

            //std::cout << "curCursor: " << curCursor << " curThreads: " << curThreads << std::endl;

            manipulateArray <<<1, curThreads >>> (devGPUMemory, curCursor, amount);
        }
    }


    cudaStatus = cudaDeviceSynchronize();

    // Copy output vector from GPU buffer to host memory.
    cudaStatus = cudaMemcpy(indexArray, devGPUMemory, inputData->indexArrayCount * sizeof(long), cudaMemcpyDeviceToHost);

    long max = 0;
    for (long i = 0; i < inputData->indexArrayCount; i++)
    {
        //std::cout << indexArray[i] << " ";
        
        if (indexArray[i] > max) max = indexArray[i];
    }
    std::cout << std::endl;

    cudaFree(devGPUMemory);

    return max;
}

int main()
{
    std::fstream fin("input.txt");

    std::cout << "Matrix Manipulation using GPU." << std::endl;

    struct input newInput {};

    fin >> newInput.indexArrayCount >> newInput.queryCount;

    newInput.inputQueryRow = (struct inputQueryRow*)malloc(newInput.queryCount * sizeof(struct inputQueryRow));

    for (long i = 0; i < newInput.queryCount; i++)
        fin >> newInput.inputQueryRow[i].rangeMin >> newInput.inputQueryRow[i].rangeMax >> newInput.inputQueryRow[i].amount;

    long max = maxSum(&newInput);

    std::cout << "Max Sum: " << max << std::endl;

    return 0;
}