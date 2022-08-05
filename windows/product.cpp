#include <iostream>
#include <cstring>

// compiled with visual studio 2019

void validate_serial_key(char* serial_key) {
    char* next_token;
    char* token = strtok_s(serial_key, "-", &next_token);
    int num = atoi(token);
    if (num < 1337 || num > 3337) {
        printf("Invalid serial key number.\n");
        exit(EXIT_FAILURE);
    }

    token = strtok_s(NULL, "-", &next_token);
    num = atoi(token);
    if (num < 7337 || num > 9337) {
        printf("Invalid serial key number.\n");
        exit(EXIT_FAILURE);
    }

    token = strtok_s(NULL, "-", &next_token);
    num = atoi(token);
    if (num < 1000 || num % 2 == 0) {
        printf("Invalid serial key number.\n");
        exit(EXIT_FAILURE);
    }

    token = strtok_s(NULL, "-", &next_token);
    num = atoi(token);
    if (num < 1000 || num % 2 != 0) {
        printf("Invalid serial key number.\n");
        exit(EXIT_FAILURE);
    }

    printf("Congratz!, Product Activated Successfully!\n");
    exit(EXIT_SUCCESS);
}

void main(int argc, char **argv) {
    if (argc != 2) {
        printf("Please enter your serial key number to activiate the product.\n");
        printf("e.g -> ./product 1111-2222-3333-4444\n");
        exit(EXIT_FAILURE);
    }
    validate_serial_key(argv[1]);
}