#include<stdio.h>

int main(){


  int a =9;
  int* p = &a;
  printf("ADDR of p is %d\n",p);

  void* p1 = p;
  printf("ADDR of p1 is %d\n",p1);
       //you can't derefrance or do pointer arth to void*
      //its only used to get the memeory addrs
}
