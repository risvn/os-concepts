#include<stdio.h>


//NOTE:
//char* test="hell0 world!";
//Here, "hello world" is a string literal, which is typically stored in read-only memory. Trying to modify it causes undefined behavior (often a crash).

int main(){
char test[]="hell0 world!";
char result[100];
int len=0;

while(test[len]!='\0') len++;

int new=0;
int idx=0;
while(len--){

//for smaller alphabets
//  ASCI VALUES 65-90 captials 97-122 small
if (!(test[new] >= 'a' && test[new] <= 'z'))
  {
  new++; 
      }
  else{
       result[idx++]=test[new++];
  }
}

printf("%s",result);
return(0);
}
