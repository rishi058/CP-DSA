#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node* nextRight;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
        nextRight = NULL;
    }
};

void bfs(Node *root)              
{
    queue<Node*> q;
    q.push(root);  

    while(!q.empty())
    {
        int n = q.size();
        for(int i=1; i<=n; i++){
            Node* temp = q.front();
            q.pop();
            
            if(i==n){
                temp->nextRight=NULL;
            }

            if(i!=n){
               temp->nextRight=q.front();
            }

            if(temp->left!=NULL){  
                q.push(temp->left);

            }
            
            if(temp->right!=NULL){  
                q.push(temp->right);

            }
        }
        
    }

}

void Solution(Node* root) {
    bfs(root);
    return ;  
}

int main()
{
    Node ten(10);
    Node three(3);
    Node five(5);
    Node four(4);
    Node one (1);
    Node two (2);

    ten.left = &three;
    ten.right = &five;

    five.right = &two;

    three.left = &four;
    three.right = &one;

    Solution(&ten);

}