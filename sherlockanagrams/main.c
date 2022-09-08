#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int numQueries;
    scanf("%d", &numQueries);

    char* string;

    for ( int i=0; i<numQueries; i++ )
    {
        scanf("%s", string );
        printf("%s", string );
    }

    fclose(fptr);

    return 0;
}