#include <bits/stdc++.h>
using namespace std;

// Morris Traversal
// Space Complexity- O(1)
// Time Complexity- O(N)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorder(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right and prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                ans.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    
    return 0;
}