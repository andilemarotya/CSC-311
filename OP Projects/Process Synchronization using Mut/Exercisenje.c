#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_t tid[4]; // Store the tid's for the 4 threads
float shared = 64.0; // Shared Variable
pthread_mutex_t lock;
/// All the 4 threads:
    
    
do{

    while(compare_and_swap(&lock,0,1) !=0 ){
        //do nothing
    }    
    void* incr(void* arg)
    {
    // No Mutexes
 
     printf("Before incr(): %f\n",shared);
     shared += 1;                        // critical section
     printf("After incr(): %f\n",shared);
  
     return NULL;
    }

    void* decr(void* arg)
    {
        // No Mutexes
        printf("Before decr(): %f\n",shared);
        shared -= 1;                        //critical section
        printf("After decr(): %f\n",shared);
 
        return NULL;
    
    }

    void* doubles (void* arg)
    {
    // We lock before doubling
 
    printf("Before double(): %f\n",shared);
    shared *= 2;
    printf("After double(): %f\n",shared);
  

    return NULL;
    }

    void* halve(void* arg)
    {
        // We lock before halving
  
        printf("Before halve(): %f\n",shared);
        shared /= 2;
        printf("After halve(): %f\n",shared);
  
    
        return NULL;
    }


}while(true);

int main(void)
{
  int error;
  
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

  

  return 0;
}