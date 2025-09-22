#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define BUFFER_SIZE 10
#define PRODUCERS  3 
#define CONSUMERS   2 

typedef struct {

  pthread_mutex_t mutex; 
  sem_t empty_slots; 
  sem_t full_slots; 
  int data[BUFFER_SIZE];
  int count;

}SharedBuffer;

SharedBuffer buffer={0};

int buffer_init(SharedBuffer* buffer)
{
  buffer->count=0;
  sem_init(&buffer->empty_slots,0,BUFFER_SIZE);
  sem_init(&buffer->full_slots,0,0);
  pthread_mutex_init(&buffer->mutex,NULL);
  return 0;
}



void produce_item(SharedBuffer* buffer,int item)
{
  //oder does matter if you grab the mutex and slepping on semaphore it leads to the deadlocks
  //wait for the empty_slots
  sem_wait(&buffer->empty_slots);
  
  //get the mutex loc
  pthread_mutex_lock(&buffer->mutex);

  //write in to buffer
  buffer->data[buffer->count++]=item;
  printf("Produced: %d (Buffer: %d)\n", item, buffer->count);
  
  //unlock the semaphore order doesnt matter 
  pthread_mutex_unlock(&buffer->mutex);
  sem_post(&buffer->full_slots);
}



int consume_item(SharedBuffer* buffer)
{
  sem_wait(&buffer->full_slots);

  pthread_mutex_lock(&buffer->mutex);

  //write in to buffer
  int item=buffer->data[--buffer->count];
  printf("Consumed: %d (Buffer: %d)\n", item, buffer->count);
  

  pthread_mutex_unlock(&buffer->mutex);
  sem_post(&buffer->empty_slots);
  return item;
}



void* producer_thread(void* arg)
{
  for(int i=0;i<5;i++){
    produce_item(&buffer,i*100);
  }

  return NULL;
}


void* consumer_thread(void* arg)
{
  for(int i=0;i<5;i++){
    consume_item(&buffer);
  }
  return NULL;
}


int main()
{
  pthread_t producer_count[PRODUCERS];
  pthread_t consumer_count[CONSUMERS];

  
  buffer_init(&buffer);

  //producer thread
  for(int i=0;i<PRODUCERS;i++)
  {
    pthread_create(&producer_count[i],NULL,producer_thread,NULL);

  }
  
  //consumer thread
  for(int i=0;i<CONSUMERS;i++)
  {
    pthread_create(&consumer_count[i],NULL,consumer_thread,NULL);

  }
  

  //join threads
  for(int i=0;i<PRODUCERS;i++)
  {
    pthread_join(producer_count[i],NULL);

  }

  for(int i=0;i<CONSUMERS;i++)
  {
    pthread_join(consumer_count[i],NULL);

  }


return 0;
}



