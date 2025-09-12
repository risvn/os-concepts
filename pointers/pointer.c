#include<stdio.h>



int main(){

  int a= 9;
  //initalizing the pointer
  int* p = &a;  
  printf("p is the pointer to the location:[%p]\n",(void*)p);

 //pointer derefrance
  printf("the value in a before deref is %d\n",a);
  *p= 5;
  printf("the value in a after deref is %d\n",a);
}
