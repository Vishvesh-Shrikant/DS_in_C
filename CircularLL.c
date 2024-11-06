#include <malloc.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node *next;
} * start;

void create(int n) {
  struct Node *temp, *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = n;
  if (start == NULL) {
    start = newnode;
    newnode->next = start;
  } else {
    temp = start;
    while (temp->next != start) {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = start;
  }
}

void display() {
  struct Node *temp = start;
  if (temp == NULL) {
    printf("List is empty");
    return;
  }
  do {
    printf("%d\t", temp->data);
    temp = temp->next;
  } while (temp != start);
}

void insert_before(int n, int val) {
  struct Node *ptr, *newnode, *prev;
  newnode = (struct Node *)malloc(sizeof(struct Node));

  newnode->data = n;
  ptr = start;

  if (ptr == NULL) {
    start = newnode;
    newnode->next = start;
  } else {
    prev = ptr;
    if (ptr->data == val) {
      newnode->next = ptr;
      start = newnode;
      ptr->next = start;
      return;
    }
    while (ptr->next != start) {
      prev = ptr;
      ptr = ptr->next;
    }
    if (ptr == start) {
      printf("List item not found , enter correct value");
    } else {
      prev->next = newnode;
      newnode->next = ptr;
    }
  }
}

void insert_after(int n, int val) {
  struct Node *ptr, *newnode, *prev;
  newnode = (struct Node *)malloc(sizeof(struct Node));

  newnode->data = n;
  ptr = start;

  if (ptr == NULL) {
    start = newnode;
    newnode->next = start;
  } else {
    prev = ptr;
    if (ptr->data == val) {
      newnode->next = ptr;
      start = newnode;
      ptr->next = start;
      return;
    }
    while (prev->next != start && prev->data != val) {
      prev = ptr;
      ptr = ptr->next;
    }
    if (prev == start) {
      printf("List item not found , enter correct value");
      return;
    } else {
      prev->next = newnode;
      newnode->next = ptr;
    }
  }
}

void deleteNode(int n) {
  struct Node *ptr, *prev;
  ptr = start, prev = NULL;
  if (ptr == NULL) 
  {
    printf("\nLIST IS EMPTY\n");
    return;
  }

  while ( ptr->next != start && ptr->data != n) 
  {
    prev = ptr;
    ptr = ptr->next;
  }
  if (ptr == start && ptr->data != n) 
  {
    printf("\nELEMENT NOT FOUND\n");
    return;
  }
  if (ptr == start && ptr->data == n) 
  {
    start = start->next;
    free(ptr);
  } 
  else if (ptr->data == n) 
  {
    prev->next = ptr->next;
    free(ptr);
  }
}

int main(void) {
  create(6);
  insert_before(4, 6);
  insert_before(3, 6);
  insert_before(2, 6);
  insert_after(7, 6);
  insert_after(8, 6);
  insert_after(9, 6);
  deleteNode(8);
  display();
}