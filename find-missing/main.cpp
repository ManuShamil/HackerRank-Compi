#include <iostream>
#include <map>
#include <vector>

int main()
{
    int inputArray[] = { 1, 1};
    int inputArrayLength = 2;

    std::map<int,int> hashMap;

    int lowestNum = inputArray[0], highestNum = inputArray[0];


    for ( int i=0; i<inputArrayLength; i++ )
    {
        if ( inputArray[i] < lowestNum )
            lowestNum = inputArray[i];
        
        if ( inputArray[i] > highestNum )
            highestNum = inputArray[i];

        hashMap[inputArray[i]] += 1;
    }


    std::map<int, int>::iterator hashMapIterator;

    int nextNum = hashMap.begin()->first;
    std::vector<int> missingNums;

    for( hashMapIterator = hashMap.begin(); hashMapIterator != hashMap.end(); hashMapIterator++ )
    {
        int curNum = hashMapIterator->first;

        while ( curNum != nextNum )
        {
            missingNums.push_back( nextNum );
            nextNum++;
        }

        nextNum++;
    }

    for( int i=0; i<missingNums.size(); i++ )
        std::cout << missingNums[i] << " ";

    std::cout << std::endl;



    return 0;
}

