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

void postorder(struct node* root)
{
    // if the current node is empty
    if (root == NULL) {
        return;
    }
 
    // Traverse the left subtree
    postorder(root->left);
 
    // Traverse the right subtree
    postorder(root->right);
 
    // Display the data part of the root (or current node)
    printf("%d -> ", root->key);
}

void preorder(struct node* root)
{
    // if the current node is empty
    if (root == NULL) {
        return;
    }
 
    // Display the data part of the root (or current node)
    printf("%d -> ", root->key);
 
    // Traverse the left subtree
    preorder(root->left);
 
    // Traverse the right subtree
    preorder(root->right);
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

void INORDER(){
  printf("\nInorder traversal: ");
  inorder(root);
  printf("\n");
}

void PREORDER(){
  printf("\nPreorder traversal: ");
  preorder(root);
  printf("\n");
}

void POSTORDER(){
  printf("\nPostorder traversal: ");
  postorder(root);
  printf("\n");
}

int main() {

    system("cls");
    printf("THIS IS A PROGRAM FOR RECURSIVE TRAVERSING IN PREORDER, POSTORDER, INORDER OF A BINARY SEARCH TREE (BST) \n\n");

    root = insert(root, 8); root = insert(root, 10); root = insert(root, 14);
    root = insert(root, 3); root = insert(root, 6); root = insert(root, 13);
    root = insert(root, 1); root = insert(root, 4); root = insert(root, 7);

    printf("\nGiven Tree : \n");
    printf("                 8               \n");
    printf("               /   \\              \n");
    printf("              3      10             \n ");
    printf("           /    \\     \\            \n");
    printf("         1      6        14           \n");
    printf("              /   \\      /           \n");
    printf("             4     7    13           \n\n");

    

    while(1>0)
    {
        printf("\nPress 1 to execute preorder traversing in BST. ");
        printf("\nPress 2 to execute postorder traversing in BST. ");
        printf("\nPress 3 to execute inorder traversing in BST. \n");
        printf("Press 4 to EXIT. \n\n");

        int n; scanf("%d", &n);
        switch (n)
        {
        case 1 : PREORDER(); break;
        case 2 : POSTORDER(); break;
        case 3 : INORDER(); break;
        case 4 : return 0;
        
        default: printf("\nInvalid Input"); break;
        }
    }

}
