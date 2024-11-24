#include <stdio.h>
#include<malloc.h>  

struct Node{
  int data;
  struct Node *next;
} *start;

void create(int val)
{
  struct Node *nn, *ptr;
  nn=(struct Node*)malloc(sizeof(struct Node));
  nn->data=val;
  if(start==NULL)
  {
    nn->next=NULL;
    start=nn;
    return;
  }
  ptr=start;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  nn->next=NULL;
  ptr->next=nn;
}

void insertBefore(int val, int key)
{
  struct Node *nn, *ptr, *prev;
  nn= (struct Node*)malloc(sizeof(struct Node));
  nn->data=val;
  if(start->data==NULL)
  {
    nn->next=NULL;
    start=nn;
  }
  else 
  {
    ptr=start;
    if(ptr->data==key)
    {
      nn->next=ptr;
      start=nn;
      return;
    }
    while(ptr->next!=NULL && ptr->data !=key)
    {
      prev=ptr;
      ptr=ptr->next;
    }
    if(ptr==NULL)
    {
      printf("\nKey not found\n");
      return;
    }
    prev->next=nn;
    nn->next=ptr;
  }
}

void inserAfter(int val, int key)
{
  struct Node *nn, *ptr;
  nn= (struct Node*)malloc(sizeof(struct Node));
  nn->data=val;
  if(start->data==NULL)
  {
    nn->next=NULL;
    start=nn;
    return;
  }
  ptr=start;
  while(ptr!=NULL && ptr->data!=val )
  {
    ptr=ptr->next;
  }
  if(ptr==NULL)
  {
    printf("\nKEY NOT FOUND\n");
    return;
  }
  nn->next=ptr->next;
  ptr->next=nn;
}

float average()
{
  struct Node *ptr;
  int counter=0;
  float sum=0;
  ptr=start;
  while(ptr!=NULL)
    {
      counter++;
      sum+=ptr->data;
      ptr=ptr->next;
    }
  return sum/counter;
}

void reversed()
{
  struct Node *ptr, *prev, *next;
  if(start==NULL)
  {
    printf("\nList is empty\n");
    return;
  }
  ptr=start, prev=NULL;
  while(ptr!=NULL)
  {
      next=ptr->next;
      ptr->next=prev;
      prev=ptr;
      ptr=next;
  }
  start=prev;
}

void deleteNode(int val)  
{
    struct Node *ptr, *prev;
    if(start==NULL)
    {
      printf("\nList is empty\n");
      return;
    }
    ptr=start, prev=NULL;
    if(ptr->data==val)
    {
        start=start->next;
        free(ptr);
    }
    while(ptr!=NULL && ptr->data!=val)
      {
        prev=ptr;
        ptr=ptr->next;
      }
    if(ptr==NULL)
    {
      printf("\nValue not found\n");
      return;
    }
    prev->next=ptr->next;
    free(ptr);
}

void display()
{
  struct Node *ptr;
  ptr=start;
  printf("\n");
  while(ptr!=NULL)
  {
    printf("%d\t", ptr->data);
    ptr=ptr->next;
  }
}


int main(void)
  {
    create(5);
    insertBefore(2,5);
    inserAfter(10,5);
    inserAfter(11,5);
    inserAfter(13,5);
    display();
    deleteNode(5);
    reversed();
    display();
  }
