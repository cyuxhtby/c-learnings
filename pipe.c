# include <stdio.h>     // Provides printf for output
# include <stdlib.h>    // Provides exit for terminating the program
# include <string.h>    // Provides strlen for string length calculation
# include <unistd.h>    // Provides fork, pipe, read, write, and close for IPC and process control
# include <sys/types.h> // Provides pid_t for storing process IDs

// Parent and child processes can share data via the use of "pipes"
// The data exchange uses pipe() as the communication link and fork() to create a new process 

int main() {

    // "pipe file descriptors" holds two values
    // 0 is used to read from the pipe
    // 1 is used to write to the pipe
    int pipefd[2];

    if(pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // fork() duplicates the current process and returns a value for its role (parent or child).
    // We store it as a "process id"
    pid_t pid = fork();

    // pid > 0: Code is running in the parent process
    // pid == 0: Code is running in the child process
    // pid == -1: Fork failed
    if (pid == 0) {
        // The size of the buffer determines how much data we can store from the pipe
        char buffer[20];
        // Close the write end of the pipe
        close(pipefd[1]);
        // Read data from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        // Print received data
        printf("Child received: %s\n", buffer);
        // Close read end of pipe
        close(pipefd[0]);
    }
    else {
        const char *message = "Hello, child!";
        close(pipefd[0]);
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
    }

    // An output of "Child received: Hello, child!" confirms that the data "Hello, child!" was successfully sent from the parent process to the child process via the pipe 

    return 0;
}
