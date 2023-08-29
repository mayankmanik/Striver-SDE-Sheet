#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive 

void postorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

// Iterative

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    stack<TreeNode *> st;
    while (curr or !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                while (!st.empty() and temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else
                curr = temp;
        }
    }
    return ans;
}

int main()
{

    return 0;
}