#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int* convertToPrefixSumArray( int* array, int arrayLength )
{
    int* newArray = (int*) malloc ( arrayLength * sizeof(int) );

    newArray[0] = array[0];

    for ( int i=1; i<arrayLength; i++)
        newArray[i] = array[i] - array[i-1];

    return newArray;
}

int* convertFromPrefixArray( int* array, int arrayLength )
{
    int* newArray = (int*) malloc ( arrayLength * sizeof(int) );\

    newArray[0] = array[0];
    for ( int i=1; i<arrayLength; i++ )
        newArray[i] = newArray[i-1] + array[i];
    
    return newArray;
}

int main()
{
    int sizeOfArray = 10;
    int defaultArray[10] = { 4, 4, 32, 45, 12, 65, 123, 542, 12, 10 };    

    int* prefixSumArray = convertToPrefixSumArray( defaultArray, 10 );

    for ( int i=0; i<10; i++)
        cout << prefixSumArray[i] << " ";

    cout << endl;

    int* originalArray = convertFromPrefixArray( prefixSumArray, 10);

    // for( int i=0; i<10; i++ )
    //     originalArray[i] = prefixSumArray[i] + originalArray[i - 1 ];

    for( int i=0; i<10; i++ )
        cout << originalArray[i] << " "; 

    cout << endl;

    return 0;
}