#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "q1.h"

int main() {
	char input_file[50];
	char output_file[50];

	printf("Please enter the input file name: ");
	scanf("%49s", input_file);

	printf("\nPlease enter the output file name: ");
	scanf("%49s", output_file);

	int check = fileChecker(input_file, output_file);
	printf("fileChecker went through");

	if (check == 1) {
		printf("Both files are clear for copying!");
		copyDirectory(input_file, output_file);
	} else {
		printf("\nNot cleared to copy:(");
	}

	return 1;
}

int fileChecker(char input_file[], char output_file[]) {

	DIR *dp;
	struct dirent *ep;
	int success = 1;
	int input_found = 0;
	int output_found = 0;
	int input_comparison;
	int output_comparison;
	int dir_removed;

	mode_t mode = 0777;
	int dir_created;

	dp = opendir("./");
	if (dp != NULL) {
		while (ep = readdir(dp)) {
			output_comparison = strcmp(ep->d_name, output_file);
			input_comparison = strcmp(ep->d_name, input_file);
			printf("%s\n", ep->d_name);
			//Checking to see if output file exists
			if (output_comparison == 0) {
				printf("woah woah woah, output file already exists");
				printf("\nTime to delete :)");

				//Removing file if it already exists
				dir_removed = rmdir(output_file);

				if (dir_removed == 0) {
					printf("\nRemoval was a success!");
					success = 1;
				} else {
					printf("\nRemoval failed :(\n");
					success = 0;
				}

			}

			if (input_comparison == 0) {
				input_found = 1;
			}

		}
		//Making output directory
		dir_created = mkdir(output_file, mode);
		if (dir_created == 0) {
			printf("directory created, ready to copy babyyy");
		} else {
			perror("This is the error creating the file: ");
		}

		//Checking to see if input file exists
		if (input_found == 0) {
			printf("\ndawg, there's no input file with that name");
			success = 0;
		} else if (input_found == 1) {
			printf("\nInput file exists :)");
		}
		(void) closedir(dp);
	} else
		perror("Couldn't open the directory");

	return success;

}

int copyDirectory(char input_file[], char output_file[]) {

	DIR *dp;
	struct dirent *ep;
	struct dirent *ep_source;
	struct dirent *ep_destination;

	dp = opendir("./");
	if (dp != NULL) {
		while (ep = readdir(dp)) {
			//Finding the input directory
			if (strcmp(ep->d_name, input_file) == 0) {
				ep_source = ep;
				printf("\nInput File found and copied");
				printf("\n%s", ep_source->d_name);
			}
			//Finding the output directory
			if (strcmp(ep->d_name, output_file) == 0) {
				ep_destination = ep;
				printf("\nOutput File found and copied");
				printf("\n%s", ep_destination->d_name);
			}

			ep_destination = ep_source;
		}
		(void) closedir(dp);
	} else
		perror("Couldn't open the directory");

	return 0;
}


