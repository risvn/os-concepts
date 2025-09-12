#include<stdio.h>

void increment(int* a){

  *a=*a+1;

}

int main (){
  int a =9;
 increment(&a); 
printf("the value of a is %d\n",a);
}
