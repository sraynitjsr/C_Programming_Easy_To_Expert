#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to be executed by each thread
void *thread_function(void *thread_id) {
    int tid = *((int *) thread_id) + 1;
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (result) {
            printf("Error creating thread %d\n", i);
            return -1;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished\n");

    return 0;
}
