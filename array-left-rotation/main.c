#include<stdio.h>

struct TestCase
{
    int n;
    int d;
    int *array;
    int *outputArray;
};

int testInputArray[] = {1, 2, 3, 4, 5};
int testOutputArray[] = {5, 1, 2, 3, 4};

struct TestCase CASE1 = {
    5,
    4,
    testInputArray,
    testOutputArray
};

int testInputArray2[] = {33,47,70,37,8,53,13,93,71,72,51,100,60,87,97};
int testOutputArray2[] = {87,97,33,47,70,37,8,53,13,93,71,72,51,100,60};

struct TestCase CASE2 = {
    15, 
    13,
    testInputArray2,
    testOutputArray2
};

/**
* @a_count: Number of elements in input array
* @a: The array to be rotated.
* @d: Number of rotations.
* @result_count: Total No. elements in reversed array?
*/
int* rotLeft(int a_count, int* a, int d, int* result_count) {

    *result_count = a_count;

    int tempA;
    int rotationsDone = 0;


    // for ( int i=0; i<a_count; i++)
    //     printf("%d ", a[i]);
    // printf("\n");

    while ( rotationsDone < d )
    {
        tempA = a[0]; //! store first element to temp.

        //! shift every element to the left.
        for ( int i=0;i<a_count; i++ )
            *(a + i ) = *( a + (i+1) );

        *(a + a_count -1) = tempA;

        rotationsDone++;

        // for ( int i=0; i<a_count; i++)
        //     printf("%d ", a[i]);
        // printf("\n");
    }

    return a;
}

int main()
{
    int result_count;
    int* output = rotLeft(CASE1.n, CASE1.array, CASE1.d, &result_count);

    for ( int i=0; i<result_count; i++)
    {
        if ( output[i] != CASE1.outputArray[i] )
        {
            printf("TEST CASE 1 FAILED!!\n");
            return 1;
            break;
        }
    }

    printf("TEST CASE 1 PASSED!!\n");

    output = rotLeft(CASE2.n, CASE2.array, CASE2.d, &result_count);

    for ( int i=0; i<result_count; i++)
    {
        if ( output[i] != CASE2.outputArray[i] )
        {
            printf("TEST CASE 2 FAILED!!\n");
            return 1;
            break;
        }
    }

    printf("TEST CASE 2 PASSED!!\n");
    return 0;
}