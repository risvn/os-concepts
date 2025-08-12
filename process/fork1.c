#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc,char* argv[])
{
  int rc=fork();                         //two identical process are created

  if(rc>0)                       // pid>0 running parent process  
  {
  printf("[%d] parent of [%d]  \n",(int)getpid(),rc);
  }
  else if(rc==0)                       //child process 
  {
  printf("child process  (pid): [%d]\n",(int)getpid());
  }
  else
  {
    perror("fork failed\n");
  }

  return 0;
  }
