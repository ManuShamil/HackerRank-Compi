// Matrix Manipulation using GPU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>

struct inputQueryRow
{
    int rangeMin, rangeMax, amount;
};

struct input
{
    int indexArrayCount, queryCount;
    struct inputQueryRow* inputQueryRow;
};

long maxSum(struct input* inputData)
{
    int* indexArray = (int*)malloc(inputData->indexArrayCount * sizeof(int));

    for (int i = 0; i < inputData->queryCount; i++)
    {

    }

}

int main()
{
    std::fstream fin("input.txt");

    std::cout << "Matrix Manipulation using GPU." << std::endl;

    struct input newInput {};

    fin >> newInput.indexArrayCount >> newInput.queryCount;

    newInput.inputQueryRow = (struct inputQueryRow*) malloc (newInput.queryCount * sizeof(struct inputQueryRow));

    for (int i = 0; i < newInput.queryCount; i++)
        fin >> newInput.inputQueryRow[i].rangeMin >> newInput.inputQueryRow[i].rangeMax >> newInput.inputQueryRow[i].amount;
    
    maxSum(&newInput);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
