#include <bits/stdc++.h>
using namespace std;


// You are given a BST with' N' number of nodes and a value X. Your task is to find the greatest value node of the BST which 
// is smaller than or equal to X.
// Note:X is not smaller than the smallest node of BST.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int floorInBST(TreeNode* root, int X)
{
    int ans=-1;
    while(root)
    {
        if(root->val<=X)
        {
            ans=root->val;
            root=root->right;
        }
        else if(root->val>X)    root=root->left;
    }
    return ans;
}

int main()
{
    
    return 0;
}