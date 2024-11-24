#include <stdio.h>
#include <malloc.h>

struct Node{
    int data, priority;
    struct Node *next;
} *start;

void insert(int val, int priority)
{
    struct Node *nn, *prev, *ptr;
    nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=val;
    nn->priority=priority;
    if(start==NULL)
    {
        nn->next=NULL;
        start=nn;
        return;
    }
    ptr=start, prev=start;
    if(priority < ptr->priority)
    {
        nn->next= ptr;
        start=nn;
        return;
    }
    while(ptr->next!=NULL && ptr->next->priority <= priority )
    {
        ptr=ptr->next;
    }
    nn->next=ptr->next;
    ptr->next=nn;
}

void deleteNode()
{
    struct Node *ptr=start;
    if(start==NULL)
    {
        printf("Priority Queue Empty");
        return;
    }
    printf("\n Deleted data is : %d", ptr->data);
    start=start->next;
    free(ptr);
}

void display()
{
    struct Node *ptr;
    ptr=start;
    printf("\n\n");
    while(ptr!=NULL)
    {
        printf("%d [pri= %d] \t", ptr->data, ptr->priority);
        ptr=ptr->next;
    }
}

int main() {
    // Write C code here
    insert(1,2);
    insert(2,1);
    insert(3,3);
    insert(4,2);
    insert(5,5);
    insert(6,4);
    display();
    deleteNode();
    deleteNode();
    display();
    return 0;
}
