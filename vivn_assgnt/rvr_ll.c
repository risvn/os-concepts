#include<stdlib.h>
#include<stdio.h>

typedef struct node{
int data;
struct node* nxt;
} node;

void add_node(node** head,node* nd){

  nd->nxt=*head;
  *head=nd;

}


void print_ll(node* head) {
    node* tmp = head;
    while (tmp) {
        printf("%d\n", tmp->data);
        tmp = tmp->nxt;
    }
}



  

void reverse(node* head){
   
//reverse it!

  }}


int main(){


  node* head=malloc(sizeof(node));
  head->data=0;
  head->nxt=NULL;

for(int i=1;i<5;i++){

  node* nd=malloc(sizeof(node));
  nd->data=i;
  nd->nxt=NULL;
  add_node(&head,nd);
  }

  print_ll(head);
 
}




