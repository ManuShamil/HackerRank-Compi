#include <stdio.h>
#include <stdlib.h>


/**====================================
*   TEST INPUTS
*/
int TESTINPUT[6][6] = {
    -9,     -9,     -9,     1,      1,      1,
    0,      -9,     0,      4,      3,      2,
    -9,     -9,     -9,     1,      2,      3,
    0,      0,      8,      6,      6,      0,
    0,      0,      0,      -2,     0,      0,
    0,      0,      1,      2,      4,      0
};

/**====================================
*   TEST INPUTS
*/
int TESTOUTPUT[4][4] = {
    -63,    -34,    -9,     12, 
    -10,    0,      28,     23, 
    -27,    -11,    -2,     10, 
    9,      17,     25,     18
};

int EXPECTED_RESULT = 28;

struct Coordinate
{
    int r;
    int c;
};

struct Coordinate relativeHourGlassCoordinates[] = {
    { -1, -1 }, { -1, 0 }, { -1, 1},
    { 1, -1 }, {1, 0 }, { 1, 1}
};

int hourglassSum(int arr_rows, int arr_columns, int** arr)
{
    struct Coordinate borderMin = { r: 1, c: 1 };
    struct Coordinate borderMax = { r: 4, c: 4 };

    struct Coordinate* coordnatesToCheckFor = malloc ( 4 * 4 * sizeof( struct Coordinate ) );

    int counter = 0;
    for ( int i=borderMin.r; i<=borderMax.r; i++ )
        for ( int j=borderMin.c; j<=borderMax.c; j++ )
        {
            printf("r:%d c:%d \n", i, j);
            struct Coordinate currentCoordinate = { r: i, c: j}; 
            coordnatesToCheckFor[counter++] = currentCoordinate;
        }

    int* hourGlassSumArray = malloc ( 4 * 4 * sizeof( int ) );

    for ( int i=0; i<16; i++)
    {
        struct Coordinate coordinateCur = coordnatesToCheckFor[i];

        int r = coordinateCur.r;
        int c = coordinateCur.c;

        int sum=0;

        sum += *(*(arr + r) + c);
        for ( int j=0; j<6; j++ )
        {
            struct Coordinate relativeToCheck = relativeHourGlassCoordinates[j];
            int relativR = coordinateCur.r + relativeToCheck.r;
            int relativC = coordinateCur.c + relativeToCheck.c;

            sum += *(*(arr + relativR) + relativC );
        }

        hourGlassSumArray[i] = sum;
    }

    int loopBreaker = 0;
    for ( int i=0; i<16; i++)
    {
        if ( loopBreaker % 4 == 0)
        {
            loopBreaker = 0;
            printf("\n");
        }

        printf("%d ", hourGlassSumArray[i]);

        loopBreaker++;
    }

    int highest = hourGlassSumArray[0];

    for ( int i=0; i<16; i++)
        if ( hourGlassSumArray[i] > highest )
            highest = hourGlassSumArray[i];

    return highest;
}

int main()
{
    int** arr = malloc(6 * sizeof(int*));

    for ( int i=0; i<6; i++)
    {
        *(arr + i) = malloc ( 6 * sizeof(int) );

        for ( int j=0; j<6; j++)
        {
            *(*(arr + i) + j) = TESTINPUT[i][j];
        }
    }

    int highest = hourglassSum( 6, 6, arr );

    printf("highest: %d", highest);

    return 0;
}