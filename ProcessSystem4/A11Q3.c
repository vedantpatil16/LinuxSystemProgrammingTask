#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define INCREMENTS_PER_THREAD 500

int counter = 0;

// Function to be executed by the threads
void* increment_counter(void* arg) {
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
        counter++; // Increment the shared variable without synchronization
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final value of counter: %d\n", counter);
    pthread_exit(NULL);
    return 0;
}
