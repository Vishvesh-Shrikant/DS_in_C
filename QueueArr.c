#include <stdio.h>
#define max 10
int queue[max];
int front=-1, rear=-1;

void enqueue(int val)
{
  if(rear==max-1)
  {
    printf("\nQueue is full\n");
    return;
  }
  if(front==-1)
  {
    front++;
    queue[++rear]=val;
  }
  else
  {
    queue[++rear]=val;
  }
}

int dequeue()
{
  if(front==-1 || front > rear)
  {
    printf("\nQueue is empty\n");
    return -9999;
  }
  return queue[front++];
}


void display()
{
  if(front==-1 || front > rear)
  {
      printf("\nQueue is empty\n");
      return;
  }
  int i;
  printf("\nQueue elements are:\n");
  for( i=front; i<=rear; i++)
  {
    printf("%d\t",queue[i]);
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