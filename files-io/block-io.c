#include<stdio.h>
#define BUFFER_SIZE 1024

int main(void)
{
  FILE* input = fopen("input.txt","r");
  FILE* output = fopen("output.txt","w");
  char buffer[BUFFER_SIZE];
  size_t length;
  
    // fread(ptr, size_of_element, number_of_elements, stream)
    length = fread(buffer, sizeof(char), BUFFER_SIZE, input);

  while(length>0)
  {
    fwrite(buffer,length,sizeof(char),output);
    length = fread(buffer, sizeof(char), BUFFER_SIZE, input);
  }
fclose(input);
fclose(output);

}
