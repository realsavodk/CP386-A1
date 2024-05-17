/*
 * 1. Create a directory (`mkdir`)
 * 2. Remove a directory (`rm -rf`)
 * 3. Get the current working directory (`pwd`)
 * 4. Changing to the parent directory (`..`)
 * 5. Reading the contents of the current directory (`ls`)
 * 6. Closing the opened directory (I can't think of a similar command)
 */

#include <stdio.h>
#include <stdlib.h>

void create_directory() {
    printf("Create directory!\n\n");
}

void remove_directory() {
    printf("Remove directory!\n\n");
}

void get_current_directory() {
    printf("Get current directory!\n\n");
}

void change_to_parent_directory() {
    printf("Change to parent directory!\n\n");
}

void read_directory() {
    printf("Read directory (ls)!\n\n");
}

void close_directory() {
    printf("Close directory (what does that even mean?)\n\n");
}

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
        switch (choice) {
            case '1':
                create_directory();
                break;
            case '2':
                remove_directory();
                break;
            case '3':
                get_current_directory();
                break;
            case '4':
                change_to_parent_directory();
                break;
            case '5':
                read_directory();
                break;
            case '6':
                close_directory();
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again!\n\n");
        }

    }

    return 0;
}
