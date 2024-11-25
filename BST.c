#include <malloc.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node *left, *right;
} * root;

void create_tree() { root = NULL; }

// inserting node
struct Node *insertElement(struct Node *root, int n) {
  struct Node *parent, *ptr, *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = n;
  newnode->left = NULL;
  newnode->right = NULL;

  if (root == NULL) {
    root = newnode;
  } else {
    parent = NULL;
    ptr = root;
    while (ptr != NULL) {
      parent = ptr;
      if (n < ptr->data)
        ptr = ptr->left;
      else if (n > ptr->data)
        ptr = ptr->right;
    }
    if (n < parent->data)
      parent->left = newnode;
    else if (n > parent->data)
      parent->right = newnode;
  }
  return root;
}

// serach node
struct Node *searchElement(struct Node *root, int val) {
  struct Node *ptr = root;
  if(ptr==NULL)
  {
    printf("tree is empty!\n");
    return NULL;
  }
  while(ptr!=NULL)
  {
    if(val < ptr->data)
      ptr=ptr->left;
    else if(val > ptr->data)
      ptr=ptr->right;
    else 
      return ptr;
  }
  return NULL;
}

// deleting node
struct Node *getSuccessor(struct Node *root) {
  root = root->right;
  while (root != NULL && root->left != NULL)
    root = root->left;
  return root;
}
struct Node *deleteNode(struct Node *root, int x) {
  struct Node *succ;
  if (root == NULL)
    return root;

  if (root->data > x)
    root->left = deleteNode(root->left, x);
  else if (root->data < x)
    root->right = deleteNode(root->right, x);
  else {
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    }
    if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }
    succ = getSuccessor(root);
    root->data = succ->data;
    root->right = deleteNode(root->right, succ->data);
  }

  return root;
}

// mirror of the tree
struct Node *mirrorImage(struct Node *root) {
  struct Node *temp;
  if (root) {
    mirrorImage(root->left);
    mirrorImage(root->right);
    // Swap the left and right children
    temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
  return root;
}

// Traversal
void preorder(struct Node *root) {
  if (root) {
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void inorder(struct Node *root) {
  if (root) {
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
  }
}
void postorder(struct Node *root) {
  if (root) {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
  }
}

// smallest node
struct Node *smallestNode(struct Node *root) {
  struct Node *ptr=root;
  if (root == NULL)
    return root;
  while(ptr->left != NULL)
  {
        ptr=ptr->left;
  }
  return ptr;
}
// largest node
struct Node *largestNode(struct Node *root) {
  struct Node *ptr=root;
  if (root == NULL)
    return root;
  while(ptr->right != NULL)
  {
        ptr=ptr->right;
  }
  return ptr;
}

//total nodes in tree
int totalNodes(struct Node *root) {
  if (root == NULL)
    return 0;
  else
    return (totalNodes(root->left) + totalNodes(root->right) + 1);
}
int countLeafNodes(struct Node *root) {
  if (root == NULL) {
      return 0;
  }
  if (root->left == NULL && root->right == NULL) {
      return 1;
  }
  return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int countInternalNodes(struct Node *root) {
  if (root == NULL || (root->left == NULL && root->right == NULL)) {
      return 0;
  }
  return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

//height of tree
int height(struct Node *root){
  int x,y;
  if(root==NULL)
    return 0;

  x=height(root->left);
  y=height(root->right);

  return x>y? x+1: y+1;
}


int main(void) {
  create_tree();
  root = insertElement(root, 9);
  root = insertElement(root, 5);
  root = insertElement(root, 6);
  root = insertElement(root, 10);
  root = insertElement(root, 21);
  root = insertElement(root, 1);
  preorder(root);

  root = deleteNode(root, 5);
  printf("\n");
  root = mirrorImage(root);
  printf("Smallest node is %d\n", smallestNode(root)->data);
  printf("Largest node is %d\n", largestNode(root)->data);
  preorder(root);
  printf("\nTotal Nodes is: %d\n", totalNodes(root));
  printf("\nLeaf Nodes is: %d\n", countLeafNodes(root));
  printf("\nInternal Nodes is: %d\n", countInternalNodes(root));
}
