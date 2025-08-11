#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<.h>

int common = 69;

void* threadfunc(void* threadid)
{
long tid=(long) threadid;
  printf("Thread #%lx  stack :%lx , common: %lx (%d)\n"
         ,tid,(unsigned long)&tid,(unsigned long)&common,common);  //prints the mainstack addrs


  pthread_exit(NULL);
}


int main(int argc,char* argv[])
{
 
  long t;
  int nthreads=2;
  if(argc>1)
  {
    nthreads=atoi(argv[1]);
   }

  pthread_t* threads=malloc(nthreads*sizeof(pthread_t));  //The pthread_t type is used to represent a thread identifier 

  printf("Main stack:%lx , common: %lx (%d)\n"
         ,(unsigned long)&t,(unsigned long)&common,common);  //prints the mainstack addrs




for(t=0;t<nthreads;t++)
{
      int rc =pthread_create(&threads[t],NULL,threadfunc,(void*) t);    
      //error handling
  if(rc)
  {
      printf("ERROR:from pthread_cread %d\n",rc);
      exit(-1);
  }                                               
}                                                
                                                
                                               
//joining the threads
 for(t=0;t<nthreads;t++){
    pthread_join(threads[t],NULL);
  }

  pthread_exit(NULL);



 return 0 ;
}
