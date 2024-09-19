#include <stdio.h>
#include <string.h>
#define max 50
char stack[max];
char expression[max];
int top=-1;

void push(char c)
{
  if(top==max-1)
  {
    printf("\nStack Overflow\n");
    return;
  }
  stack[++top]=c;
}

char pop()
{
  if(top==-1)
  {
    printf("\nStack Underflow\n");
    return '0';
  }
  return stack[top--];
}

void checkParanthesis()
{
  char popped;
  int flag=1, i;
  for(i=0;i< strlen(expression);i++)
  {
      if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
      {
        push(expression[i]);
      }
      else if(expression[i]==')' || expression[i]=='}' || expression[i]==']')
      {
          popped=pop();
          if(expression[i]==')' && (popped=='{' || popped=='['))
            flag=0;
          if(expression[i]=='}' && (popped=='(' || popped=='['))
            flag=0;
          if(expression[i]==']' && (popped=='{' || popped=='('))
            flag=0; 
      }
  }
  if(flag==0)
    printf("\nParanthesis are not balanced\n");
  else if(flag==1)
    printf("\nParanthesis are balanced\n");
}

int main(void)
{
    printf("Enter an Expression:\t");
    scanf("%s", expression);
    checkParanthesis();
}