#include<stdlib.h>
#include<stdio.h>


int main(){

  int matrix[3][3] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};

int len_matrix=9;

int row=3;
int col=3;



for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
if (i % 2 != 0){   // odd column

    printf("%d\n",matrix[2-j][i]);
      }

      else{


    printf("%d\n",matrix[j][i]);
      }

      }
}

  

  return 0;
}




