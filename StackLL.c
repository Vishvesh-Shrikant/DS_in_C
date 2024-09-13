// Online C compiler to run C program online
#include <stdio.h>
#include <malloc.h>

struct Stack{
    int data; 
    struct Stack *next;
} *top;

void pushLL(int val)
{
    struct Stack *ptr;
    ptr=(struct Stack*) malloc(sizeof(struct Stack));
    ptr->data=val;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
        return;
    }

    ptr-> next= top;
    top=ptr;
}
int popLL()
{
    if(top==NULL)
    {
        printf("\nSTACK IS EMPTY\n");
        return -999;
    }
    struct Stack *ptr;
    int val;
    ptr=top;
    top=ptr->next;
    val=ptr->data;
    free(ptr);
    return val;
}

void peekLL()
{
    if(top==NULL)
    {
        printf("\nSTACK IS EMPTY\n");
    }
    printf("\n%d\t", top->data);
}


void displayLL()
{
    struct Stack* ptr;
    ptr=top;
    if(top==NULL)
        printf("\nSTACK IS EMPTY\n");
    else
    {
        printf("\n");
        while(ptr!=NULL)
        {
            printf("%d\t", ptr->data);
            ptr=ptr->next;
        }
    }
}
int main() {
    pushLL(1);
    pushLL(2);
    pushLL(3);
    pushLL(4);
    displayLL();
    printf("\n%d", popLL());
    displayLL();
    peekLL();
    return 0;
}