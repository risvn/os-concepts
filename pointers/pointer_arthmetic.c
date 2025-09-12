#include<stdio.h>


int main(){


  int a = 9;
  int* p = &a;
  printf("ADDRS of p is %d\n",p);
  printf("size of int %d\n",sizeof(a));
  printf("ADDRS of p+1 is %d\n",p+1);
}
