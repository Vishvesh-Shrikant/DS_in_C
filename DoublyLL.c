#include <malloc.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node *next, *prev;
} * start;

void create(int n) {
  struct Node *temp, *newnode;
  int i;
  for (i = 0; i < n; i++) {
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to enter:");
    scanf("%d", &newnode->data);
    if (start == NULL) {
      newnode->next = NULL;
      newnode->prev = NULL;
      start = newnode;
    } else {
      temp = start;
      while (temp->next != NULL)
        temp = temp->next;

      temp->next = newnode;
      newnode->next = NULL;
      newnode->prev = temp;
    }
  }
}

void insert_before(int n, int val) {
  struct Node *ptr, *prev, *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = n;
  ptr = start, prev = ptr;
  if (start == NULL) {
    newnode->next = NULL;
    newnode->prev = NULL;
    start = newnode;
  } else {
    while (ptr->next != NULL && ptr->data != val) {
      prev = ptr;
      ptr = ptr->next;
    }
    if (ptr->data == val) {
      newnode->next = ptr;
      newnode->prev = prev;
      prev->next = newnode;
      ptr->prev = newnode;
    } else if (ptr == NULL && ptr->data != val)
      printf("Value not found, enter correct value");
  }
}

void insert_after(int n, int val) {
  struct Node *ptr, *prev, *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = n;
  ptr = start, prev = ptr;
  if (start == NULL) {
    newnode->next = NULL;
    newnode->prev = NULL;
    start = newnode;
  } else {
    while (prev->next != NULL && prev->data != val) {
      prev = ptr;
      ptr = ptr->next;
    }
    if (prev->data == val) {
      newnode->next = ptr;
      newnode->prev = prev;
      prev->next = newnode;
      ptr->prev = newnode;
    } else if (prev == NULL && prev->data != val) {
      printf("Value not found, enter correct value");
    }
  }
}

void deleteNode(int n)
{
  struct Node *ptr, *prev;
  ptr=start, prev=start;
  if(start==NULL)
  {
    printf("List is empty");
    return;
  }
  while(ptr->next!=NULL && ptr->data!=n)
  {
      prev=ptr;
      ptr=ptr->next;
  }
  if(ptr->data==n)
  {
    if(ptr==start)
    {
      start=start->next;
      free(ptr);
    }
    else
    {
      prev->next=ptr->next;
      ptr->next->prev=prev;
      free(ptr);
    }
  }
  else if(ptr==NULL && ptr->data!=n)
  {
    printf("\nELEMENT NOT FOUND\n");
    return;
  }
}

void display() {
  struct Node *temp = start;
  while (temp != NULL) {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(void) {
  int n = 5;
  create(n);
  insert_before(9, 3);
  insert_after(0, 3);
  display();
  deleteNode(0);
  display();
}