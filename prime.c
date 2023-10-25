#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_prime_numbers(void* arg) { // void* is a generic data type pointer
    int num = *((int*) arg); // cast void* to int* then dereference
    int is_prime;

    printf("The prime numbers of a given number %d are: ", num);
    for (int i = 2; i <= num; i++) {
        is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d, ", i);
        }
    }
    printf("\b\b \n"); // move cursor back two positions, overwrite last character with space, move to next line

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num = atoi(argv[1]);
    if (num < 2) {
        fprintf(stderr, "Error: Number must be a positive integer greater than or equal to 2\n");
        return EXIT_FAILURE;
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, print_prime_numbers, &num);
    pthread_join(thread_id, NULL);

    return EXIT_SUCCESS;
}
