#include <bits/stdc++.h>
using namespace std;

// You have been given a Binary Iree of 'N nodes, where the nodes have integer values. Your task is to find the
// in-Order, Pre-Order, and Post-Order traversals of the given binary tree.

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<vector<int>> getTreeTraversal(Node *root)
{
    vector<vector<int>> ans;
    vector<int> ino, pre, post;
    stack<pair<Node *, int>> st;
    if (!root)
        return ans;
    st.push({root, 0});

    while (!st.empty())
    {
        auto node = st.top().first;
        int num = st.top().second;
        st.pop();

        if (num == 0)
        {
            pre.push_back(node->data);
            st.push({node, num + 1});
            if (node->left)
                st.push({node->left, 0});
        }
        if (num == 1)
        {
            ino.push_back(node->data);
            st.push({node, num + 1});
            if (node->right)
                st.push({node->right, 0});
        }
        if (num == 2)
        {
            post.push_back(node->data);
        }
    }
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}

int main()
{

    return 0;
}