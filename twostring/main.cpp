#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

bool IsInOccurrenceMap( std::map<char, int> occurrenceMap, char character  ) 
{
    //std::cout << character << " -> " <<occurrenceMap[character] << endl;

    return occurrenceMap[character] > 0;
}

string twoStrings(string s1, string s2)
{
    std::map<char, int> charOccurrenceMap;
    
    //! Could implement a map here to skip duplicates.
    
    for ( int i=0; i<strlen(s1.c_str()); i++ )
    {
        if ( IsInOccurrenceMap(charOccurrenceMap, s1[i] ) ) continue;

        charOccurrenceMap[s1[i]] += 1;

        for ( int j=0; j<strlen(s2.c_str()); j++ )
        {
            if ( s1[i] == s2[j])
                return "YES";
        }
    }

    return "NO";
}

int main()
{
    ofstream fOut(getenv("OUTPUT_PATH"));

    int numTestCases;
    cin >> numTestCases;

    string s1, s2;
    string temp;

    for ( int i=0; i<numTestCases; i++ )
    {
        cin >> s1 >> s2;

        temp = s1;
        s1 = strlen(s1.c_str()) > strlen(s2.c_str()) ? s1 : s2;

        if ( s1 == s2 )
            s1 = temp;

        fOut << twoStrings( s1, s2 ) << std::endl;
    }

    fOut.close();

    return 0;
}