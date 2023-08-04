#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define INCREMENTS_PER_THREAD 100000

int counter = 0;
pthread_mutex_t mutex;

// Function to be executed by the threads
void* increment_counter(void* arg) {
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++)
    {
        // Lock the mutex before accessing the shared variable
        pthread_mutex_lock(&mutex);

        counter++; // Increment the shared variable

        // Unlock the mutex after modifying the shared variable
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    // Create two threads to increment the counter
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Final value of counter: %d\n", counter);

    return 0;
}
