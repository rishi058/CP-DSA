#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *root = NULL;

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

void INSERT(){
    printf("\nEnter a number you want to insert : ");
    int x; scanf("%d", &x);
    root = insert(root, x);
    
}

void func(){
    if(root==NULL){return;}

    while(root->left!=NULL){
      int x = root->left->key;
      root = deleteNode(root, x);
    }

    while(root->right!=NULL){
      int x = root->right->key;
      root = deleteNode(root, x);
    }

    int z = root->key;
    root=deleteNode(root, z);

}

void CREATE(){
   func();
    printf("\nNew BST created.\n");
    // struct node *root = NULL;
    return;
}

void TRAVERSE(){
  printf("\nInorder traversal: ");
  inorder(root);
  printf("\n");
}

int main() {

    system("cls");
    printf("THIS IS A PROGRAM FOR CREATING AND TRAVERSING IN A BINARY SEARCH TREE (BST) \n\n");
    
    while(1>0)
    {
        printf("\nPress 1 to create a new BST \n");
        printf("Press 2 to insert a element in BST \n");
        printf("Press 3 to traverse BST \n");
        printf("Press 4 to EXIT \n\n");

        int n; scanf("%d", &n);
        switch (n)
        {
        case 1 : CREATE(); break;
        case 2 : INSERT(); break;
        case 3 : TRAVERSE(); break;
        case 4 : return 0;
        
        default: printf("\nInvalid Input"); break;
        }
    }

}
