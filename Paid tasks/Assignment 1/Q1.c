#include <stdio.h>
#include <stdlib.h>

// C functions cannot return 2 values, and we need two user inputs.
// So it's better to keep the variables in main() and call them by reference to store the user input.
void info(char *character1, char *character2){
    printf("Enter 2 characters (with blank space): ");
    scanf("%c %c", character1, character2);
}

// function to print the diamond shape according to user inputs.
void diamond(char character1, char character2){
    printf("   %c   \n", character1);
    printf("  %c%c%c  \n", character1, character2, character1);
    printf(" %c%c%c%c%c \n", character1, character2, character2, character2, character1);
    printf("%c%c%c%c%c%c%c\n", character1, character2, character2, character2, character2, character2, character1);
    printf(" %c%c%c%c%c \n", character1, character2, character2, character2, character1);
    printf("  %c%c%c  \n", character1, character2, character1);
    printf("   %c   \n", character1);
}

int main() {
    char character1, character2;

    // calling a function info with call by reference
    info(&character1, &character2);
    // calling function diamond with characters as parameters
    diamond(character1, character2);

    return 0;
}
