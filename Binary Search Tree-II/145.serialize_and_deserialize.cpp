#include <bits/stdc++.h>
using namespace std;

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored
in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another
computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization
algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be
deserialized to the original tree structure.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode *root)
{
    if (!root)
        return "";
    queue<TreeNode *> q;
    q.push(root);
    string str = "";
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr == NULL)
            str.append("#,");
        else
            str.append(to_string(curr->val) + ',');
        if (curr != NULL)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return str;
}

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
            node->left = NULL;
        else
        {
            auto left = new TreeNode(stoi(str));
            node->left = left;
            q.push(left);
        }
        getline(s, str, ',');
        if (str == "#")
            node->right = NULL;
        else
        {
            auto right = new TreeNode(stoi(str));
            node->right = right;
            q.push(right);
        }
    }
    return root;
}

int main()
{

    return 0;
}