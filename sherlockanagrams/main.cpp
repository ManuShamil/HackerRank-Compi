#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

class Seeker
{
    public:
        int seekerPos;
        int seekerSize;

        Seeker(int i, int size )
        {
            this->seekerPos = i;
            this->seekerSize = size;
        }

        ~Seeker()
        {
            
        }

        bool matchReverse( string item, Seeker *matcher )
        {
            std::cout << item << std::endl;
            std::cout << "Seeker::matchReverse -> " << std::endl;
            std::cout << "SeekerPos: " << this->seekerPos << std::endl;
            std::cout << "seekerSize: " << this->seekerSize << std::endl;
            std::cout << "reverseSeekerPos: " << matcher->seekerPos << std::endl;
            std::cout << "reverseSeekerSize: " << matcher->seekerSize << std::endl;

            for ( int i=this->seekerPos; i<this->seekerPos+this->seekerSize; i++ )
                for ( int j=matcher->seekerPos; j>matcher->seekerPos-matcher->seekerSize; j--)
                    if ( item[i] != item[j] )
                        return false;
            
            return true;
        }

        void resetTo( int index )
        {
            this->seekerPos = index;
        }

        void reset()
        {
            this->seekerPos = 0;
        }
};

class AnagramProcessor
{
    private:
        string processingItem;
        Seeker *seeker;
        int stringLength;
    public:

        int anagramCount = 0;

        AnagramProcessor( string item )
        {
            this->processingItem = item;
            this->seeker = new Seeker(0, 1);
        }

        ~AnagramProcessor()
        {
            free(this->seeker);
        }

        void processItem()
        {
            // start seeking from position 0.

            this->stringLength = strlen( this->processingItem.c_str() );

            Seeker *reverseSeeker = new Seeker(this->stringLength-1, this->seeker->seekerSize);

            while( this->seeker->seekerSize <= this->stringLength - 1)
            {
                reverseSeeker->seekerSize = this->seeker->seekerSize;

                for ( int i=0; i<this->stringLength; i++ )
                {
                    reverseSeeker->seekerPos = this->stringLength - 1 - i;

                    int result = this->seeker->matchReverse( this->processingItem, reverseSeeker );
                    std::cout << "matchReverse: " << result << std::endl;
                    std::cout << "=====================================" << std::endl;

                    this->anagramCount += result;

                    this->seeker->seekerPos++;
                }

                this->seeker->seekerSize++;
            }
        }
};

int getSubStringAnagrams( string item )
{
    AnagramProcessor *newProcessor = new AnagramProcessor( item );
    newProcessor->processItem();
    int result = newProcessor->anagramCount;

    free( newProcessor );

    return result;
}

int main()
{
    ofstream fOut(getenv("OUTPUT_PATH"));

    int numQueries;
    cin >> numQueries;

    for ( int i=0; i<numQueries; i++ )
    {
        string inputString;

        cin >> inputString;

        cout << "Result: " << getSubStringAnagrams( inputString ) << endl;

        //fOut << getSubStringAnagrams( inputString ) << endl;
    }

    fOut.close();

    return 0;
}