#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& ump, int& rootIdx, int left, int right) {
        if(left > right) return NULL;
        
        int pivot = ump[postorder[rootIdx]];
        TreeNode* node = new TreeNode(postorder[rootIdx]);
        rootIdx--;

        node->right = buildTreeHelper(inorder, postorder, ump, rootIdx, pivot+1, right);
        node->left = buildTreeHelper(inorder, postorder, ump, rootIdx, left, pivot-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = postorder.size()-1;
        unordered_map<int, int> ump;
        for(int i=0;i<inorder.size();i++) ump[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, ump, rootIdx, 0, inorder.size()-1);
    }

void print(TreeNode *ans){
    cout<<ans->val<<" ";

    if(ans->left!=NULL){
        print(ans->left);
    }
    if(ans->right!=NULL){
        print(ans->right);
    }
}

int32_t main()
{
    RISHI
    vi ino = {9,3,15,20,7};
    vi post = {9,15,7,20,3};

    TreeNode *ans = buildTree(ino, post);

    print(ans);

}