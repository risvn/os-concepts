#include<stdlib.h>
#include<stdio.h>

typedef struct node{
int data;
struct node* nxt;
} node;

void append_node(node* head,int data){
  node* tmp=head;
  node* last_node;
  while(tmp){
  last_node=tmp;
  tmp=tmp->nxt;
  }


  node* new_node=malloc(sizeof(node));
  new_node->data=data;
  new_node->nxt=NULL;
  
  last_node->nxt=new_node;


  
  }

node* get_nthnode(node* head,int n){
  node* tmp=head;
  while(n){
    tmp=tmp->nxt;
  n--;
  }
  return tmp;
}



node* reverse(node* head){
  node* tmp=head;
  node* current=head;
  node* prev=NULL;
  node* next=NULL;


  while(current){
  
    next=current->nxt;
    current->nxt=prev;
    prev=current;
    current=next;


  //rv_logic




  }
  return prev;

}

int main(){
  node* head=malloc(sizeof(node));
  head->data=1;

  int arr[]={2,4,5,6,-1}; 

  int i=0;
  while(arr[i]!=-1){


    append_node(head,arr[i]);
    i++;
  }

  node* rv_head=reverse(head);
  node* tmp=rv_head;
  while(tmp){
    printf("%d\n",tmp->data);
  tmp=tmp->nxt;
  }


    //node* nth_node=get_nthnode(head,4);
   // printf("%d\n",nth_node->data);
  return 0;
}






