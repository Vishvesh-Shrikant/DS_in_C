#include<stdio.h>
#include<malloc.h>

struct Node{
  int coeff, power;
  struct Node *next;
} *res, *start1, *start2;

struct Node *create (struct Node *start)
{
  int i,n,coeff, power;
  struct Node *ptr, *nn;
  
  
  printf("Enter number of terms:");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      printf("\nEnter coeffficient:");
      scanf("%d",&coeff);
      printf("\nEnter power:");
      scanf("%d",&power);
      nn= (struct Node*) malloc (sizeof(struct Node));
      nn->coeff=coeff;
      nn->power=power;
      
      if(start==NULL)
      {
        nn->next=NULL;
        start=nn;
      }
      else
      {
        ptr=start;
        while(ptr->next!=NULL)
        {
          ptr=ptr->next;
        }
        nn->next=NULL;
        ptr->next=nn;
      }
    }
  printf("\n");
  return start;
}
struct Node *addSubtract(struct Node *start1, struct Node *start2, struct Node *res,  int choice)
{
  struct Node *t1, *t2, *ptr, *nn;
  t1=start1;
  t2=start2;
  while(t1!=NULL && t2!=NULL)
    {
      nn=(struct Node*)malloc(sizeof(struct Node));
      if(t1->power==t2->power)
      {   
        nn->coeff=t1->coeff+((choice==1?1:-1)*t2->coeff);
        nn->power=t1->power;
        t1=t1->next;
        t2=t2->next;
      }
      else if(t1->power > t2->power) 
      {
        nn->coeff=t1->coeff;
        nn->power=t1->power;
        t1=t1->next;
      }
      else if(t1->power < t2->power )
      {
        nn->coeff=t2->coeff;
        nn->power=t2->power;
        t2=t2->next;
      }
      nn->next=NULL;
      if(res==NULL)
      {
        res=nn;
      }
      else
      {
        ptr=res;
        while(ptr->next!=NULL)
          {
            ptr=ptr->next;
          }
        ptr->next=nn;
      }
  }
  while(t1!=NULL)
    {
      nn=(struct Node*)malloc(sizeof(struct Node));
      nn->coeff=t1->coeff;
      nn->power=t1->power;
      ptr=res;
      while(ptr->next!=NULL)
        {
          ptr=ptr->next;
        }
      ptr->next=nn;
      t1=t1->next;
    }
  while(t2!=NULL)
    {
      nn=(struct Node*)malloc(sizeof(struct Node));
      nn->coeff=t2->coeff;
      nn->power=t2->power;
      ptr=res;
      while(ptr->next!=NULL)
        {
          ptr=ptr->next;
        }
      ptr->next=nn;
      t2=t2->next;
    }
  return res;
}

void display(struct Node *start)
{
  struct Node *ptr;
  ptr=start;
  while(ptr!=NULL)
  {
    printf("%dx^%d" , ptr->coeff, ptr->power);
    ptr=ptr->next;
    if(ptr!=NULL)
      printf(" + ");
  }
  printf("\n");
}
int main()
{
  start1=NULL, start2=NULL;
  start1= create(start1);
  start2=create(start2);
  res=addSubtract(start1, start2, res, 1);
  display(res);
  return 0;
}
