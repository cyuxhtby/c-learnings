# include <stdio.h>

int main() {
    // FILE is standard library structure for handling file streams
    // The asterisk is used to define a pointer variable
    FILE *file;
    char c;

    // Open file in read mode
    // Other modes are "w" for write, "a" for append, "r+" for read and write
    file = fopen("../text.txt", "r");

    // Returning a non-zero value indicates that an error occured
    // Unique return codes can indicate specific errors
    if(file == NULL) {
        printf("File not found\n");
        return 1;
    }

    // "file get character" of current pointer and set it to `c`
    // Check if `c` is not the end-of-file indicator 
    while ((c = fgetc(file)) != EOF) {
        // Writes a character to the standard output (typically the terminal)
        putchar(c);
    }

    fclose(file);
    return 0;
}