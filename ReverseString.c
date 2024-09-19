#include <stdio.h>
#include <math.h>
#include <string.h>
#define max 100
char stack[max], top=-1, rev[max], inp[max];

//for operators of the stack
void push(char c)
{
  if(top==max-1)
  {
    printf("Stack overflow");
    return;
  }
  stack[++top]= c;
}
char pop()
{
  if(top==-1)
  {
    printf("Stack underflow");
    return ' ';
  }
  return stack[top--];
}
void reverse(char c[])
{
  int len=strlen(c), i=0;
  for(i=0;i<len;i++)
    {
      push(c[i]);
    }
  i=0;
  while(top!=-1)
    {
      rev[i++]=pop();
    }
  rev[i]='\0';
}

int main(void)
{
  printf("Enter a string:");
  gets(inp);
  reverse(inp);
  printf("\nReversed string is: %s", rev);
}

