/**
 * Demonstrates bounded buffer with 2 producers and 2 consumers.  Buffer
 * contains integers. The output can be sorted to verify correct behaviour
 * by invoking as: ./prodcons | sort
 */
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

// bounded buffer data
int buffer[BUFFER_SIZE];
int pIndex = 0;
int cIndex = 0;
sem_t spaces;
sem_t filled;
pthread_mutex_t mutex;

/**
 * Produce an item and add it to the buffer.
 *
 * @param id the id of the producing thread
 * @return the produced item
 */
int produce(int id)
{
    static int count = 0;
    int oldCount = __sync_fetch_and_add(&count, 1); // atomic increment
    printf("Producer %d produced %d.\n", id, oldCount);
    return oldCount;
}

void consume(int id, int number)
{
    printf("Consumer %d consumed %d.\n", id, number);
}

/**
 * Producer thread function that generates items and adds them to a bounded buffer.
 *
 * @param arg A pointer to the integer ID of the producing thread.
 *
 * The function continuously produces a fixed number of items, waits for space
 * in the buffer, writes the item into the buffer, and signals that an item
 * has been added. The buffer access is synchronized using semaphores and a mutex
 * to ensure mutual exclusion.
 */

void *producer(void *arg)
{
    int *id = (int *)arg;

    for (int i = 0; i < 10; ++i)
    {
        // produce
        int num = produce(*id);

        // add to bounded buffer
        sem_wait(&spaces);
        pthread_mutex_lock(&mutex);
        buffer[pIndex] = num;
        pIndex = ++pIndex % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&filled);
    }
}

/**
 * Consumer thread function that continuously consumes items from a bounded buffer.
 *
 * @param arg A pointer to the integer ID of the consuming thread.
 *
 * The function continuously consumes a fixed number of items, waits for an item
 * to be available in the buffer, takes the item from the buffer, and signals that
 * a slot has been freed up. The buffer access is synchronized using semaphores and a
 * mutex to ensure mutual exclusion.
 */
void *consumer(void *arg)
{
    int *id = (int *)arg;

    for (int i = 0; i < 10; ++i)
    {
        int num = -1;
        // get from bounded buffer
        sem_wait(&filled);
        pthread_mutex_lock(&mutex);
        num = buffer[cIndex];
        buffer[cIndex] = -1; // not necessary
        cIndex = ++cIndex % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&spaces);

        // consume
        consume(*id, num);
    }
}

int main(int argc, char *argv[])
{
    // initialize bounded buffer
    sem_init(&spaces, 0, BUFFER_SIZE); // pshared 0 = shared by threads
    sem_init(&filled, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    int idNum[] = {0, 1};

    // create 2 producer threads
    pthread_t pIds[2];
    for (int i = 0; i < 2; i++)
        pthread_create(&pIds[i], NULL, producer, &idNum[i]);

    // create 2 consumer threads
    pthread_t cIds[2];
    for (int i = 0; i < 2; i++)
        pthread_create(&cIds[i], NULL, consumer, &idNum[i]);

    // join threads
    for (int i = 0; i < 2; i++)
        pthread_join(pIds[i], NULL);
    for (int i = 0; i < 2; i++)
        pthread_join(cIds[i], NULL);

    // clean up
    sem_destroy(&spaces);
    sem_destroy(&filled);
    pthread_mutex_destroy(&mutex);
}
