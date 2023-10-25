#include <stdio.h>
#include <stdlib.h> // Provides atoi for converting strings to integers
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void generate(int n){
    int fib[n]; 
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++){
        fib[i] = fib[i - 1] + fib[i - 2]; 
    }

    printf("Child: The first %d numbers in the Fibonacci sequence are: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d", fib[i]); 
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_terms>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num = atoi(argv[1]); 
    if (num <= 0) {
        fprintf(stderr, "Error: Number of terms must be a positive integer\n");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // child process
        generate(num);
    } else {
        // parent process
        wait(NULL);
        printf("Parent: The child process is done!\n");
    }

    return EXIT_SUCCESS;
}
