#include<stdio.h>
#include<string.h>

/**=========================
*
*/
struct TestCase {
    char* s;
    long n;
    long out;
};

struct TestCase CASE1 = {"aba", 10, 7 };
struct TestCase CASE2 = {"a", 1000000000000, 1000000000000 };

/**=========================
*
*/

int numCharsInStringUntilSubString( char* s, int n )
{
    int numCharsInString = 0;
    for ( int i=0; i < n; i++ )
        if ( s[i] == 'a' )
            numCharsInString += 1;
    return numCharsInString;
}

long repeatedString(char* s, long n) 
{
    int wordLength = strlen(s);
    long numberOfWordsFitInsideN = n/wordLength;
    int leftOverCharsLength = n%wordLength;

    printf("%ld %d\n", numberOfWordsFitInsideN, leftOverCharsLength);

    return (numberOfWordsFitInsideN * numCharsInStringUntilSubString(s, wordLength)) + numCharsInStringUntilSubString( s, leftOverCharsLength);
}

/**=========================
*
*/
int main()
{
    
    if ( repeatedString( CASE1.s, CASE1.n ) == CASE1.out )
        printf("TEST CASE 1 PASSED!!\n");
    else
        printf("TEST CASE 1 FAILED!\n");

    if ( repeatedString( CASE2.s, CASE2.n ) == CASE2.out )
        printf("TEST CASE 2 PASSED!!\n");
    else
        printf("TEST CASE 2 FAILED!\n");
    

    return 0;
}