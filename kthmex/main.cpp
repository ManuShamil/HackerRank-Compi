#include <stdio.h>
#include <iostream>

int kthMex(int N, int K, int A[]) {
    // code here
    
    int* missingNums = (int*) malloc (N * sizeof(int));
    int writeHeader = 0;

    int maxNum = A[0];
    for ( int i=0; i<N; i++)
    {
        if ( A[i] > maxNum ) maxNum = A[i];
    }
    
    for ( int i=0; i<maxNum; i++ )
    {
        bool found = false;
        for( int j=0; j<N; j++ )
        {
            if ( i == A[j] )
            {
                found = true;
                break;
            }
        }
        
        if ( !found ) missingNums[writeHeader++] = i;
        
        if ( writeHeader >= K ) break;
    }
    
    for( int i=0; i<K; i++)
    {
        std::cout << missingNums[i] << std::endl;
    }
    return missingNums[K -1];
}


int main()
{
    int N, K;
    std::cin >> N >> K;
    
    int* array = (int*) malloc ( N * sizeof(int) );
    for ( int i=0; i<N; i++)
        std::cin >> array[i];
    
    std::cout << kthMex( N, K, array ) << std::endl;
}