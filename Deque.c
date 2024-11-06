#include <stdio.h>
#define max 5


int queue[max], front=-1, rear=-1;

// FRONT= LEFT , REAR = RIGHT

void display()
{
    int i=front;
    if(i==-1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    while(i != rear)
    {
        printf("%d\t", queue[i]);
        i=(i+1)%max;
    }
    printf("%d\t", queue[i]);
}
//inserting at end of queue(right)
void insert_rear(int val)
{
    if((rear+1)%max==front)
    {
        printf("\nQueue is Full\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%max;
    queue[rear]=val;
}
//inserting at start (left)
void insert_front (int val)
{
    if((rear+1)%max==front)
    {
        printf("\nQueue is Full\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        front=(front-1+max)%max;
    }
    queue[front]=val;
}
//deleting from start (right)
int delete_front()
{
    if(front==-1)
    {
        printf("\nQueue is Empty\n");
        return -999;
    }
    int val=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front=(front+1)%max;
    return val;
}
//delete from end(left)
int delete_rear()
{
    if(rear==-1)
    {
        printf("\nQueue is Empty\n");
        return -999;
    }
    int val=queue[rear];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else    
       rear=(rear-1+max)%max;
    return val;
    
}

void inputRestricted()
{
    int opt, inp;
    do
    {
    printf("\n1.Input right\n2.Delete right\n3.Delete left\n4.Back\n");
    printf("Enter choice:");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1:
            printf("Enter num to be added:");
            scanf("%d", &inp);
            insert_rear(inp);
            break;
        case 2:
            inp=delete_front();
            printf("Value removed is: %d\n", inp);
            break;
        case 3:
            inp=delete_rear();
            printf("Value removed is: %d\n", inp);
            break;
        case 4:
            break;
        default:
            printf("Enter correct option!");
    }
    }while(opt!=4);
}
void outputrestricted()
{
    int opt, inp;
    do
    {
        printf("\n1.Input right\n2.Input left\n3.Delete\n4.Back\n");
        printf("Enter choice:");
        scanf("%d", &opt);
        switch(opt)
        {
        case 1:
            printf("Enter num to be added:");
            scanf("%d", &inp);
            insert_rear(inp);
            break;
        case 2:
            printf("Enter num to be added:");
            scanf("%d", &inp);
            insert_front(inp);
            break;
        case 3:
            inp=delete_front();
            printf("Value removed is: %d\n", inp);
            break;
        case 4:
            break;
            default:
            printf("Enter correct option!");
        }
    }while(opt!=4);
}

int main()
{
    int opt;
    do
    {
        printf("\n1.Input Restricted\n2.Output Restricted\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d", &opt);
        switch(opt)
        {
        case 1:
           inputRestricted();
            break;
        case 2:
           outputrestricted();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Enter correct option!");
        }
    }while(opt!=4);
        return 0;
}