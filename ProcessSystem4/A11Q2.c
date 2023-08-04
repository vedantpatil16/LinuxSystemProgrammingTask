#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* print_numbers(void* arg) {
    int start = *(int*)arg;
    for (int i = start; i < start + 5; i++) {
        printf("Thread %lu: %d\n", pthread_self(), i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2, thread3;
    int start1 = 1, start2 = 100, start3 = 1000;

    // 1
    pthread_create(&thread1, NULL, print_numbers, &start1);

    // 2
    pthread_attr_t detached_attr;
    pthread_attr_init(&detached_attr);
    pthread_attr_setdetachstate(&detached_attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread2, &detached_attr, print_numbers, &start2);

    // 3
    pthread_attr_t custom_attr;
    pthread_attr_init(&custom_attr);
    size_t stack_size = 4096; // 4KB stack size
    pthread_attr_setstacksize(&custom_attr, stack_size);
    pthread_create(&thread3, &custom_attr, print_numbers, &start3);

    // Wait for all threads to complete
    pthread_join(thread1, NULL);
    // thread2 is detached and won't be joined explicitly
    pthread_join(thread3, NULL);

    printf("All threads have finished.\n");
    pthread_exit(NULL);
    return 0;
}
