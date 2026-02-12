
#include<stdio.h>

//| What you want              | Syntax  | Type                          | Example            |
//| -------------------------- | ------- | ----------------------------- | ------------------ |
//| Single character           | `'a'`   | `char`                        | `char c = 'a';`    |
//| String (sequence of chars) | `"abc"` | `char[N]` (decays to `char*`) | `char* s = "abc";` |


//  char* s ="hello";     //read-only memory this s[1]="k";

int main(){
  char* fruits[]={"orange","banana","cat"};
  char* sorted_fruits[3];
  int used[3] = {0};   // mark used elements
  int len=3;



for(int i=0;i<len;i++){
  int min_idx=-1;

    for(int j=0;j<len;j++){
      if(used[j]) continue;
      if(min_idx==-1||fruits[min_idx][0]>fruits[j][0]) min_idx=j; 
    }
     sorted_fruits[i]=fruits[min_idx];
      used[min_idx]=1;

}

    for (int i = 0; i < len; i++) {
        printf("%s\n", sorted_fruits[i]);
    }


  return 0;
}
