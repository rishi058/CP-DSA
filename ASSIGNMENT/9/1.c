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

void search(struct node* root, int value) 
{ 
    // while is used to traverse till the end of tree
    while (root != NULL){

        // checking condition and passing right subtree & recusing 
        if (value > root->key) 
            root = root->right; 

        // checking condition and passing left subtree & recusing 
        else if (value < root->key) 
            root = root->left; 
        else{
            printf("Element founded");
            return;
        }
    } 
    printf("Element Not Found");
    return;
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

void DELETE(){
    printf("\nEnter the number you want to delete : ");
    int x; scanf("%d", &x);
    root = deleteNode(root, x);

}

void SEARCH(){
    printf("\nEnter the number you want to search for : ");
    int x; scanf("%d", &x);
    search(root, x);
    
}

void DISPLAY(){
  printf("\nInorder traversal: ");
  inorder(root);
  printf("\n");
}

int main() {

    system("cls");
    printf("THIS IS A PROGRAM FOR INSERTION, DELETION ANS SEARCH IN A BINARY SEARCH TREE (BST) \n\n");
    
    while(1>0)
    {
        printf("\nPress 1 to insert a element in BST \n");
        printf("Press 2 to delete a element in BST \n");
        printf("Press 3 to search a element in BST \n");
        printf("Press 4 to display BST \n");
        printf("Press 5 to EXIT \n\n");

        int n; scanf("%d", &n);
        switch (n)
        {
        case 1 : INSERT(); break;
        case 2 : DELETE(); break;
        case 3 : SEARCH(); break;
        case 4 : DISPLAY(); break;
        case 5 : return 0;
        
        default: printf("\nInvalid Input"); break;
        }
    }

}
