#include<stdio.h>

int max=10;
int stack[10], topSt=-1;
void push(int val)
{
    if(topSt==max-1)  
    {
      printf("\nSTACK OVERFLOW\n");
      return;
    }
    stack[++topSt]=val;
}

int pop()
{
    if(topSt==-1)
    {
        printf("\nSTACK UNDERFLOW\n");
        return -9999;
    }
    return stack[topSt--];
}
void peek()
{
    if(topSt==-1)  
    {
      printf("\nSTACK IS EMPTY\n");
      return;
    }
    printf("\n%d\t", stack[topSt]);
}
void display()
{
  if(topSt==-1)
  {
    printf("\nSTACK IS EMPTY\n");
    return;
  }
  int i;
  printf("\n");
  for(i=topSt;i>=0;i--)
  {
    printf("%d\t", stack[i]);    
  }
}

int main()
{
  push(1);
  push(2);
  push(3);
  push(4);
  display();
  printf("\n%d", pop());
  display();
  peek();
  return 0;
}

