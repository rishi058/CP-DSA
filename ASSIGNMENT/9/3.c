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

int count = 0;
int countnodes(struct node *root)
{

    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

int main() {

    system("cls");
    printf("THIS IS A PROGRAM FOR COUNTING NUMBER OF NODES IN A BINARY SEARCH TREE (BST) \n\n");

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
        printf("\nPress 1 to count the number of nodes in BST. ");
        printf("\nPress 2 to EXIT. \n\n");

        int n; scanf("%d", &n);
        switch (n)
        {
        case 1 : count = 0; countnodes(root); printf("\nTotal No. of Nodes in the Given BST is : %d\n", count); break;
        case 2 : return 0;
        
        default: printf("\nInvalid Input"); break;
        }
    }

}
