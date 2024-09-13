#include <stdio.h>
#include <malloc.h>

struct Queue{
  int data; 
  struct Queue *next;
} *front, *rear;

void enqueue(int val)
{
  struct Queue *ptr;
  ptr= (struct Queue*)malloc(sizeof(struct Queue));
  ptr->data=val;
  if(front==NULL)
  {
    ptr->next= NULL;
    front=ptr;
    rear=ptr;
  }
  else
  {
    ptr->next=NULL;
    rear->next=ptr;
    rear=ptr;
  }
}
int dequeue()
{
  if(front==NULL)
  {
    printf("\nQueue is empty\n");
    return -999;
  }
  struct Queue *ptr;
  int val;
  ptr=front;
  front=ptr->next;
  val=ptr->data;
  free(ptr);
  return val;
}

void display()
{
    if(front==NULL)
    {
        printf("\nQueue is empty\n");
    }
    struct Queue *ptr;
    ptr=front;

    while(ptr!=NULL)
      {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
      }
}


int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  display();
  printf("\nValue deleted is: %d\n", dequeue());
  display();
}