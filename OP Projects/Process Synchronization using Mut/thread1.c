#include<stdio.h> 
#include <string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 

pthread_t tid[2]; 
int counter; 

void* doSomeThing(void *arg){ 
  unsigned long i = 0; 
  counter += 1; //when called for first time counter is incremented so it counts number of jobs run
  printf("\n Job %d started\n", counter); 

  for(i=0; i<(0xFFFFFFFF);i++); 
  printf("\n Job %d finished\n", counter); 
  return NULL;
 } 

int main(void) { 
   int i = 0; //var to check num args
   int err; //var to check for error when creating a thread
   while(i < 2) 
     { 
       err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL); //creates thread and passes in function and thread id
       if (err != 0) 
         printf("\ncan't create thread :[%s]", strerror(err)); //prints error if failed to create thread 
       i++; 
     }
   pthread_join(tid[0], NULL); //waits for thread respective to thread id to terminate
   pthread_join(tid[1], NULL); 
   return 0; 
 }


