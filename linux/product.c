#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// compile: gcc product.c -o product

void validateSerialKey(char *serialKey) {
	/* first part */
	char *token = strtok(serialKey, "-");
	int num = atoi(token);
	if (num < 1337 || num > 3337) {
		printf("Invalid serial-key number\n");
		exit(1);
	}

	/* second part */
	token = strtok(NULL, "-");
	num = atoi(token);
	if (num < 7337 || num > 9337) {
		printf("Invalid serial-key number\n");
		exit(1);
	}

	/* third part */
	token = strtok(NULL, "-");
	num = atoi(token);
	if (num < 1000 || num % 2 == 0) {
		printf("Invalid serial-key number\n");
		exit(1);
	}

	/* fourth part */
	token = strtok(NULL, "-");
	num = atoi(token);
	if (num < 1000 || num % 2 != 0) {
		printf("Invalid serial-key number\n");
		exit(1);
	}
	printf("Congratz!, Product Activated Successfully.\n");
	exit(0);
}

void main(int argc, char **argv) {
	if (argc != 2) {
		printf("Please enter your serial key number to activiate the product.\n");
		printf("e.g -> ./product 1111-2222-3333-4444\n");
		exit(1);
	}
	validateSerialKey(argv[1]);
}
