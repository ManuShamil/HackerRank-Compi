#include <stdio.h>
#include <stdlib.h>

int *swapCountArray;

int recordSwap( int num, int arrayLength )
{

    swapCountArray[num] += 1;

    //printf("SWAPCOUNT: %d -> %d\n", num, swapCountArray[num]);

    return swapCountArray[num];
}

int seekNum( int numToSearch, int seek, int *array, int arrayLength )
{
    for ( int i=seek; i<arrayLength; i++ )
        if ( array[i] == numToSearch )
            return i;
    
    return -1;
}

/**
*   @returns number of swaps.
*/
int swapBackTo( int from, int to, int* array, int arrayLength )
{
    int numberOfSwaps = 0;

    for ( int j=from; j>to; j-- )
    {
        if (recordSwap( array[j-1] > array[j] ? array[j-1] : array[j], arrayLength) > 2)
        {
            printf("Too chaotic\n");
            return -1;
        }

        int temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;

        

        // for ( int i=0; i<8; i++ )
        //     printf("%d ", array[i] );

        // printf("\n");

        numberOfSwaps++;
    }
    
    return numberOfSwaps;
}

void minimumBribes(int arrayNumCount, int* array) {

    swapCountArray = malloc ( arrayNumCount * sizeof(int) );

    int* resultantArray = array;
    for( int i=0; i<arrayNumCount; i++ ) resultantArray[i] = resultantArray[i] - 1;

    // for ( int i=0; i<arrayNumCount; i++ )
    // {
    //     printf("%d ", resultantArray[i] );
    
    //     if ( i > 20 )
    //         break;
    // }

    int numSwaps = 0;

    for ( int i=0; i<arrayNumCount; i++ )
    {
        int currentNum = i;

        //! item misplaced, seek in array.
        if ( currentNum != array[i] )
        {
            int elemPosition = seekNum( i, currentNum, array, arrayNumCount );

            //printf("%d\n", elemPosition);
            if ( elemPosition == -1 ) return;

            int swaps = swapBackTo(elemPosition, i, array, arrayNumCount);

            if ( swaps == - 1)
                return;
            
            numSwaps += swaps;
        }
    }

    printf("%d\n", numSwaps);
 
}

int main()
{
    int numTestCases;

    scanf("%d", &numTestCases);

    for( int i=0; i<numTestCases; i++ )
    {
        printf("TEST CASE %d\n", i);

        int arrayLength;

        scanf("%d", &arrayLength);

        int* array = malloc ( arrayLength * sizeof( int ) );
        for (int k=0; k<arrayLength; k++ )
            scanf("%d", &array[k]);

        
        minimumBribes( arrayLength, array );
    }

    return 0;
}