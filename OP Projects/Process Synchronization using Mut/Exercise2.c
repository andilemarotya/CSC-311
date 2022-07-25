//3934655                       Mandile Marotya                     Prac2 Exercise 2 Operating Systems

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_t tid[4]; // Store the tid's for the 4 threads
float shared = 64.0; // Shared Variable
pthread_mutex_t lock;
/// All the 4 threads:
void* incr(void* arg)
{
  // We lock before incrementing
  
  pthread_mutex_lock(&lock);
  printf("Thread 1 acquired the lock");
  printf("Before Thread 1 = incr(): %f\n",shared);
  shared += 1;
  printf("After Thread 1 = incr(): %f\n",shared);
  pthread_mutex_unlock(&lock);
  printf("Thread 1 released the lock");

  return NULL;
}

void* decr(void* arg)
{
  // We lock before decrementing
  pthread_mutex_lock(&lock);
  printf("Thread 2 acquired the lock");
  printf("Before Thread2 decr(): %f\n",shared);
  shared -= 1;
  printf("After Thread2 decr(): %f\n",shared);
  pthread_mutex_unlock(&lock);
  printf("Thread 2 released the lock");

  return NULL;
}

void* double_ (void* arg)
{
  // We lock before doubling
  pthread_mutex_lock(&lock);
  printf("Thread 3 acquired lock");
  printf("Before Thread 3 = double(): %f\n",shared);
  shared *= 2;
  printf("After Thread 3 = double(): %f\n",shared);
  pthread_mutex_unlock(&lock);
  printf("Thread 3 acquired lock");

  return NULL;
}

void* halve(void* arg)
{
  // We lock before halving
  pthread_mutex_lock(&lock);
  printf("Thread 4 acquired the lock");
  printf("Before Thread4 = halve(): %f\n",shared);
  shared /= 2;
  printf("After Thread 4 = halve(): %f\n",shared);
  pthread_mutex_unlock(&lock);
  printf("Thread 4 released the lock");

  return NULL;
}


int main(void)
{
  int error;
  pthread_mutex_init(&lock, NULL);
  /// Run all the 4 threads
  pthread_create(&(tid[0]),NULL,&incr,NULL);
  pthread_create(&(tid[1]),NULL,&decr,NULL);
  pthread_create(&(tid[2]),NULL,&doubles,NULL);
  pthread_create(&(tid[3]),NULL,&halve,NULL);


  // Wait for the threads to complete:
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  pthread_join(tid[2], NULL);
  pthread_join(tid[3], NULL);

  pthread_mutex_destroy(&lock);

  return 0;
}