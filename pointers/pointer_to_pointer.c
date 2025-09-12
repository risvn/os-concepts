#include<stdio.h>


int main(){


  int a=9;
  int* p =&a;

  int** ptp= &p;
  printf("value stored in ptp is %d i.e is p\n",*ptp);
  printf("ADDR of p is %d \n",p);
  printf("value stored in a is %d \n",**ptp);


  **ptp=5;

  printf("value stored in a after deref is %d \n",**ptp);
}
