#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int count = 1;

void *printOdd(void *arg) {
    while (count <= 10) {      
        pthread_mutex_lock(&mutex);        
        if (count % 2 != 0) {
            printf("Odd: %d\n", count++);
        }      
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *printEven(void *arg) {
    while (count <= 10) {
        pthread_mutex_lock(&mutex);
        if (count % 2 == 0) {
            printf("Even: %d\n", count++);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t oddThread, evenThread;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&oddThread, NULL, printOdd, NULL);
    pthread_create(&evenThread, NULL, printEven, NULL);

    pthread_join(oddThread, NULL);
    pthread_join(evenThread, NULL);
  
    pthread_mutex_destroy(&mutex);

    return 0;
}
