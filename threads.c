# include <stdio.h>
# include <pthread.h> // POSIX (Portable Operating System Interface) Threads
# include <math.h>

void* calculate_root(void* arg);
void* calculate_sum(void* arg);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    pthread_t thread1, thread2;

    /*
    * pthread_create: Launches a new thread
    * Args:
    *   thread (out)       : New thread ID
    *   attr (in, optional): Thread attributes
    *   start_routine (in) : Function to execute
    *   arg (in, optional) : Argument for function
    * Returns: 
    *   0 on success, error code on failure
    */

    if(pthread_create(&thread1, NULL, calculate_sum, &n)){
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if(pthread_create(&thread2, NULL, calculate_root, &n)){
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    /*
    * pthread_join: Waits for a thread to terminate
    * Args:
    *   thread (in)       : Thread ID to wait for
    *   retval (out, optional): Pointer to store exit status
    * Returns:
    *   0 on success, error code on failure
    */

    if(pthread_join(thread1, NULL)){
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    if(pthread_join(thread2, NULL)){
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    return 0;

}

void *calculate_root(void *arg) {
    int *n_pointer = (int*) arg;
    int n = *n_pointer;
    double root = sqrt((double) n);
    printf("Square root of %d is %f\n", n , root);
    return NULL;
}

void *calculate_sum(void *arg){
    int *n_pointer = (int*) arg;
    int n = *n_pointer;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    printf("The sum of integers from 1 to %d is %d\n", n , sum);
    return NULL;
}