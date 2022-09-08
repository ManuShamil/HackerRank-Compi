#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct romanNumeral {
    char* roman;
    int value;
};

struct romanNumeral DEFINITIONS[] = {
    { "I", 1 },
    { "V", 5 },
    { "X", 10 },
    { "L", 50 },
    { "C", 100 },
    { "D", 500 },
    { "M", 1000 }
};

int getValue( char numeral )
{
    for ( int i=0; i<(sizeof DEFINITIONS / sizeof *DEFINITIONS); i++ )
    {
        if ( *DEFINITIONS[i].roman == numeral )
            return DEFINITIONS[i].value;
    }

    return 0;
}

int main()
{
    int value = 0;

    char* input;
    scanf("%s", input);

    for ( int i=0; i<strlen(input); i++ )
    {
        value +=  getValue( input[i] );
    }


    return 0;
}