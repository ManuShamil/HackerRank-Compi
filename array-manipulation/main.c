#include <stdio.h>
#include <stdlib.h>

long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries)
{
    long* indexArray = (long*) malloc (n * sizeof(long));

    long max = 0;

    for( int i=0; i<queries_rows; i++ )
    {
        int* query = queries[i];

        int from = query[0];
        int to = query[1];
        int amount = query[2];

        for ( int k=from-1; k<to; k++ )
        {
            indexArray[k] += amount;
            if ( indexArray[k] > max )
                max = indexArray[k];
        }

        for( int i=0; i<n; i++)
            printf("%ld ", indexArray[i]);

        printf("\n");
        
    }


    // printf("max: %d", max);

    return max;
}

int main()
{
    int arrayLength, numOperations;

    scanf("%d %d", &arrayLength, &numOperations);

    int** operations = (int** ) malloc ( numOperations * sizeof(int* ) );

    for( int i=0; i<numOperations; i++ )
    {
        *(operations + i) = (int* ) malloc ( 3 * sizeof( int ) ); 

        for ( int j=0; j<3; j++ )
        {
            scanf("%d",*(operations + i) + j);
            //printf("%d ",*(*(operations + i) + j));
        }

        //printf("\n");
    }

    long result = arrayManipulation( arrayLength, numOperations, 3, operations );

    //printf("RESULT: %ld\n", result);

    printf( "%ld\n",result );

    return 0;
}

