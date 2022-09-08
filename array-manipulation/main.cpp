#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fOut( getenv("OUTPUT_PATH"));

    //cout << "OUT -> " << getenv("OUTPUT_PATH") << endl;

    long indexArrayLength, queriesLength;

    cin >> indexArrayLength >> queriesLength;

    long* indexArray = ( long* ) malloc ( indexArrayLength * sizeof( long ) );

    for ( long i=0; i<queriesLength; i++ )
    {
        long rangeMin, rangeMax, queryAmount;

        cin >> rangeMin >> rangeMax >> queryAmount;

        rangeMin -= 1;
        rangeMax -= 1;

        indexArray[rangeMin] += queryAmount;

        if ( rangeMax < indexArrayLength )
            indexArray[rangeMax + 1] -= queryAmount;

        // for( int j=0; j<indexArrayLength; j++ )
        //     cout << indexArray[j] << " ";
        
        //cout << endl;
    }

    long maxAmount = 0;

    for ( long i=1; i<indexArrayLength; i++ )
    {
        indexArray[i] = indexArray[i] + indexArray[i - 1];

        if ( indexArray[i] > maxAmount )
            maxAmount = indexArray[i];
    }

    //cout << maxAmount << endl;
    fOut << maxAmount << endl;
    fOut.close();


    return 0;
}