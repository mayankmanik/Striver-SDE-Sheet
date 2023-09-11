#include <bits/stdc++.h>
using namespace std;

/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. 
The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal
when next() is called.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushFill(TreeNode *root)
    {
        for(;root!=NULL;st.push(root),root=root->left);
    }
    BSTIterator(TreeNode* root) {
        pushFill(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        pushFill(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main()
{
    
    return 0;
}