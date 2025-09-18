#include<stdio.h>


#define SIZE 10

int mutex=1;
int buffer[SIZE]={0};
int empty=SIZE;
int full=0;
int in=0,out=0;


void wait(int* s)
{
   while(*s<=0);//busy wait
   (*s)--;
}


void signal(int* s)
{

   (*s)++;

}



void write(int *buffer, int item) {
    buffer[in] = item;
    in = (in + 1) % SIZE;
    printf("Produced: %d\n", item);
}

// Read item from buffer
int read(int *buffer) {
    int item = buffer[out];
    out = (out + 1) % SIZE;
    printf("Consumed: %d\n", item);
    return item;
}


int consumer(int* full,int* empty,int* mutex,int* buffer)
{
  wait(full);
  wait(mutex);
  read(buffer);
  signal(mutex);
  signal(empty);


  return 0;
}

int producer(int* full,int* empty,int* mutex,int* buffer,int item)
{
  wait(empty);
  wait(mutex);
  write(buffer,item);
  signal(mutex);
  signal(full);
  return 0;

}

int main()
{
producer(&full,&empty,&mutex,buffer,89);
consumer(&full,&empty,&mutex,buffer);
return 0;
}



