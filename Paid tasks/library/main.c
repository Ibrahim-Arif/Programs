
// Name:
// Username:
// Date started:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"

////
// Code module for main()
// main function takes command line arguments
// and opens the library menu
// Input: book data filename via command line
// Usage: ./library books.txt

int main( int argc, char **argv )
{
    char bookFile[40];

    // check that correct number of command line arguments are entered
    // use the error message
    // exit the application if there is an error
    if(argc < 3){
        printf("Error\nExpected use: ./library books.txt\n");
        return -1;
    }

    // assign command line value to filename string
    strcpy(bookFile, argv[2]);

    // DO NOT ALTER
    // start the system
    printf("\nIntialising library system!\n");
    libraryCLI( bookFile );
    printf("\nClosing library system!\n\n");

    return 0;
}

