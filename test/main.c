#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{
    int arrayLen;
    scanf("%d", &arrayLen);

    int* array = malloc ( arrayLen * sizeof( int ) );

    for( int i=0; i<arrayLen; i++ )
        scanf("%d", &array[i]);

    for( int i=0; i<arrayLen; i++ )
        printf("%d ", array[i]);

    printf("\n");

    return 0;
}