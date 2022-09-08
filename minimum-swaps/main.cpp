#include <iostream>
#include <fstream>

using namespace std;

void swapPos( int *array, int arrayLength, int from, int to )
{
    int temp = array[from];
    array[from] = array[to];
    array[to] = temp;
}

int numSwaps( int *array, int arrayLength )
{
    int swapsDone = 0;

    //! loop through every index.
    for ( int i=0; i<arrayLength; i++ )
    {
        while ( array[i] != i )
        {
            swapPos( array, arrayLength, i, array[i] );

            swapsDone++;
        }
    }

    return swapsDone;
}

int main()
{
    ofstream fOut( getenv("OUTPUT_PATH") );

    int arrayLength;
    cin >> arrayLength;

    int* array = ( int * ) malloc ( arrayLength * sizeof( int ) );
    for ( int i=0; i<arrayLength; i++ )
    {   
        int item;
        cin >> item;
        array[i] = item - 1;
    }

    int swapsDone = numSwaps( array, arrayLength );

    // for ( int i=0; i<arrayLength; i++ )
    //     cout << array[i] << " ";

    //cout << endl;

    fOut << swapsDone << endl;

    fOut.close();

    return 0;
}