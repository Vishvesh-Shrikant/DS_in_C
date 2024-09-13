#include <stdio.h>
#define max 6
int queue[max];
int rear=-1, front=-1;
void enqueue(int val)
{
  if (front == (rear + 1) % max) {
    printf("Queue is full!");
  }
  if(front==-1)
  {
    front++;
  }
  rear=(rear+1)%max;
  queue[rear]=val;
}

int dequeue()
{
  int val;
  if (front == -1) 
  {
    printf("\nQueue is empty!\n");
    return -999;
  }
  val=queue[front];
  if(front==rear)
  {
    front=-1;
    rear=-1;
  }
  else
  {
    front=(front+1)%max;
  }
  return val;
}

void display()
{
  if (front == -1) 
    {
      printf("\nQueue is empty!\n");
      return ;
    }
  int i=front;
  printf("\n");
  while( i!=rear)
    {
      printf("%d\t", queue[i]);
      i=(i+1)%max;
    }
    printf("%d\t", queue[i]);
}
int main(void)
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  enqueue(60);
  display();
  printf("\nValue deleted is:%d\n", dequeue());
  printf("\nValue deleted is:%d\n", dequeue());
  display();
  enqueue(70);
  enqueue(80);
}