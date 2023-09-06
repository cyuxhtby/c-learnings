#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *print_sec(void *arg);

int main(){
    int n1, n2;
    printf("Enter two numbers: ");
    // `&` retrieves a memory address, creating a pointer
    // scanf() expects pointers to be passed in
    scanf("%d %d", &n1, &n2);

    pthread_t thread1, thread2;
    
    if(pthread_create(&thread1, NULL, print_sec, &n1)){
        fprintf(stderr, "Error printing thread1\n");
    }

    if(pthread_create(&thread2, NULL, print_sec, &n2 )){
        fprintf(stderr, "Error printing thread2\n");
    }

    // Without this, the code will terminate prematurely
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void *print_sec(void *arg) {
    int n = *((int*)arg);
    sleep(n);
    printf("%d seconds have passed\n", n);
    return NULL;
}