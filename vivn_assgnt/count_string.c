#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int asci[250]={0};

int main(){

  char apple[]="apple";

  int arr_len=strlen(apple);

  for(int i=0;i<arr_len;i++){

  asci[(int)apple[i]]++;

  }
  
  int i=0;
  while(i<arr_len){
    
          printf("%c",apple[i]);
  if(asci[(int)apple[i]]>1 & apple[i]==apple[i+1]){

      int count=asci[(int)apple[i]];
      i=i+count-1;
      printf("%d",count);

          }
    

i++;
  }


  

}
