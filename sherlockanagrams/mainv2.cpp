#include <bits/stdc++.h>


bool compare_arrays( int *array1, int *array2, int size )
{
    for ( int i=0; i<size; i++)
    {
        if ( array1[i] != array2[size-1-i])
            return false;
    }

    return true;
}




/**
*   @returns Returns index-1 where the seeker gets collided with extreme right bound.
*/
int find_seeker_extreme_bound( int array_size, int seeker_size )
{
    return array_size - seeker_size;
}

int* array_range( int* array, int begin, int end )
{
    int newArraySize = end - begin;
    int* newArray = ( int* ) malloc( newArraySize * sizeof( int ) );

    //std::cout << "Range: [" << begin << ", " << end << "]" << std::endl;
    int bytes_written = 0;
    for ( int i=begin; i<end; i++ )
    {
        newArray[bytes_written++] = array[i];
        //std::cout << (char)newArray[bytes_written-1]<< " ";
    }

    //std::cout << std::endl;

    return newArray;
}

int anagrams_in_splice( int* array, int array_size, int* splice, int splice_size, int ignore_index )
{
    int count = 0;

    for ( int i=0; i<array_size; i++ )
    {
        if ( i == ignore_index ) continue;

        int* newSplice = array_range( array, i, i + splice_size );

        count += compare_arrays( newSplice, splice, splice_size );

    }

    return count;
}

int process_string( const char* item )
{
    int anagrams = 0;

    //! lets convert our string to numbers, so it's easy to work with? pog.
    int array_size = strlen( item );

    int* array = ( int* ) malloc ( array_size * sizeof( int ) );
    for ( int i=0; i<array_size; i++)
        array[i] = (int)item[i];

    int seeker_size = 1;

    //! expand seeker_size slowly until array_size - 1.
    while ( seeker_size < array_size )
    {
        //std::cout << seeker_size << " -> " << find_seeker_extreme_bound( array_size, seeker_size ) << std::endl;
        for ( int i=0; i<find_seeker_extreme_bound(array_size, seeker_size); i++ )
        {
            int* currentSplice = array_range( array, i, i + seeker_size );

            anagrams += anagrams_in_splice( array, array_size, currentSplice, seeker_size, i );
        }

        seeker_size++;
    }

    return anagrams;

}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));


    int numQueries;
    std::cin >> numQueries;

    for( int i=0; i<numQueries; i++ )
    {
        std::string item;

        std::cin >> item;


        int anagrams = process_string( item.c_str() );

        //std::cout << "Result: " << anagrams << std::endl;

        fout << anagrams << std::endl;
    }

    fout.close();

    return 0;
}