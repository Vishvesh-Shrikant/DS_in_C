 #include <stdio.h>
#include <math.h>
#define max 100
char stack[max], top=-1, top2=-1;
char infix[max], postfix[max];
float num[max];

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

//for evaluation stack 
void push2(float c)
{
  if(top2==max-1)
  {
    printf("Stack overflow");
    return;
  }
  num[++top2]= c;
}
float pop2()
{
  if(top2==-1)
  {
    printf("Stack underflow");
    return 0;
  }
  return num[top2--];
}



//get priority of the operators
int getPriority(char c)
{
  if( c =='(')
    return 100;
  else if(c=='+' || c=='-')
    return 200;
  else if(c=='*' || c=='/')
    return 300;
  else if(c=='^' || c=='%')
    return 400;
  else
    return -999;
}


//evaluating the postfix expression
void infixPostfix()
{
  int i=0,j=0;
  char temp, ch;
  ch=infix[i];
  while(ch!='\0')
  {
    //if number/character add from infix to postfix
    if(ch>='0' && ch<='9')
    {
      postfix[j]= ch;
      j++;
      i++;
    }
    //if ( then add to stack 
    else if(ch=='(')
    {
      push(ch);
      i++;
    }
    // if ) then pop till ( is encountered and add to postfix, then pop the (
    else if(ch==')')
    {
      while(stack[top]!='(')
      {
        postfix[j]= pop();
        j++;
      }
      temp=pop();
      i++; 
    }
    //if an operator is encountered, get priorty of operator and stack top, if priority is higher or equal to stack top then pop from stack and add to post
    else if( ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='^' || ch=='%')
    {
        while( top==-1 && (getPriority(stack[top])>=getPriority(ch)))
        {
          postfix[j]=pop();
          j++;
        }
        push(ch);
      i++;
    }
    ch=infix[i];
  }
  //pop all the operators from stack and add to postfix
  while(top!=-1)
  {
    postfix[j] = pop();
    j++;
  }
  postfix[j]='\0';
}

//evaluating the postfix expression 
float evaluate()
{
  int i=0;
  char x= postfix[i];
  float op1,op2, val=0;
  while(x!='\0')
  {
    if(x>='0' && x<='9')
    {
      push2((float)(x-'0'));
      i++;
    }
    else if( x=='+' || x=='-' || x=='*' || x=='/' || x=='%' || x=='^')
    {
      op1=pop2();
      op2=pop2();
      switch(x)
        {
              case '+':
                   val=op2+op1;
                   push2(val);
                   break;
              case '-':
                  val =op2-op1;
                  push2(val);
                  break;
              case '/':
                  val=op2/op1;
                  push2(val);
                  break;
              case '*':
                  val=op2*op1;
                  push2(val);
                  break;
              case '%':
                  val=(int)op2%(int)op1;
                  push2(val);
                  break;
              case '^':
                  val=pow(op2,op1);
                  push2(val);
                  break;
          }
          i++;
        }
    x=postfix[i];
  }
  return pop2();
}



int main(void)
{
  printf("Enter the infix expression: ");
  scanf("%s", infix);
  infixPostfix();
  printf("The postfix expression is: %s", postfix);
  printf("\nThe value of the expression is: %f", evaluate());
}
