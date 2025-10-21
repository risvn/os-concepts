/*The Producer–Consumer Problem (also called the Bounded Buffer Problem) is a classic synchronization problem in operating systems and concurrent programming.
 * It describes a scenario where two or more processes share a common, fixed-size buffer and must coordinate their actions to avoid conflicts and data inconsistency.*/


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


#define CAPACITY 30
#define PRODUCERS 5 
#define ITEMS 10 

#define FOR_EACH(item, array) \
    for (int keep = 1, \
             count = 0, \
             size = sizeof(array) / sizeof *(array); \
         keep && count != size; \
         keep = !keep, count++) \
        for (item = (array) + count; keep; keep = !keep)

//make it dynamic or random
int items[ITEMS]={1,2,3,4,5,6,7,8,9,0};


typedef struct {
    int buffer[CAPACITY];
    int full;
    int empty;
    int mutex;
    int count;
} SharedBuffer;

//wait and signal functions for semiphores and mutex
void wait(int *S) { while (*S <= 0); (*S)--; }
void signal(int *S) { (*S)++; }



//function to initilize the circular buffer
void init_buffer(SharedBuffer* buffer)
{

  buffer->full=0;
  buffer->empty=CAPACITY;
  buffer->count=0;
  buffer->mutex=1;
 
}


//reading the values
int enqueue(SharedBuffer* buff,const int item)
{
  
  
    if (buff->count == CAPACITY) {
        printf("Buffer full!\n");
        return -1;
    }
    buff->buffer[buff->count++] = item;
    return 0;
}


//adding values in to the buffer from an array
int dequeue(SharedBuffer* buff)
{
    if (buff->count == 0) {
        printf("Buffer empty!\n");
        return -1;
    }
    int item = buff->buffer[--buff->count];
    return item;
}



int produce(SharedBuffer* buff,int item)
{

  //wait
  wait(&buff->empty);   
  wait(&buff->mutex);   

  enqueue(buff,item);



  //signal
  signal(&buff->full);   
  signal(&buff->mutex);   


  return 0;

}

int consume(SharedBuffer* buff)
{

  //wait
  wait(&buff->full);   
  wait(&buff->mutex);   

  printf("%d is cosumed \n",  dequeue(buff));



  //signal
  signal(&buff->empty);   
  signal(&buff->mutex);   


  return 0;


  }



//creating threads


//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
 //   void *(*start_routine)(void*), void *arg);




int main()
{
  SharedBuffer* buff=(SharedBuffer*)malloc(sizeof(SharedBuffer));

//program crashes if you forget to initalize the buffer
  init_buffer(buff);
  FOR_EACH(int* item,items){

    produce(buff,*item);

  }
  

for(int i=0;i<ITEMS;i++){
      consume(buff);
  }


  return 0;
}


