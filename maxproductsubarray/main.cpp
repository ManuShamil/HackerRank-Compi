#include <bits/stdc++.h>

int solve( int* array, int len )
{
    int maxSum = 0;

    for( int i=0; i<len; i++ )
    {
        //! reverse seek
        for ( int j=i; j>0; j--)
        {
            
        }

        //! forward seek
        for ( int j=i;)
    }

    return 0;
}

int main()
{
    std::ofstream fOut(getenv("OUTPUT_PATH"));

    int arrayCount;
    std::cin >> arrayCount;

    int* array = (int*) malloc ( arrayCount * sizeof(int));

    for( int i=0; i<arrayCount; i++ )
    {
        std::cin >> array[i];

        fOut << array[i] << " ";
    }

    solve( array, arrayCount );

    fOut.close();

    return 0;
}