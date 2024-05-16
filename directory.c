/*
* 1. Create a directory (`mkdir`)
* 2. Remove a directory (`rm -rf`)
* 3. Get the current working directory (`pwd`)
* 4. Changing to the parent directory (`..`)
* 5. Reading the contents of the current directory (`ls`)
* 6. Closing the opened directory (I can't think of a similar command)
*/

#include <stdio.h>


char display_menu() {
    char choice;
    printf("Select the option(s) appropriately by selecting the number:\n");
    printf("1. Create a directory\n");
    printf("2. Remove a directory\n");
    printf("3. Print current working directory\n");
    printf("4. Change directory one level up\n");
    printf("5. Read the contents of the directory\n");
    printf("6. Close the current directory\n");
    printf("q. Exit the program\n");
    scanf(" %c", &choice);
    return choice;
}


int main() {

    while (1) {
        char choice = display_menu();
        printf("Your choice: %c\n\n", choice);
    } 

    return 0;
}
