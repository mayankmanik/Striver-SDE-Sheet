#include <bits/stdc++.h>
using namespace std;

// Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is 
// visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(!root)   return ans;
    queue<Node *> q;
    q.push(root);
   
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            auto node=q.front();
            q.pop();
            if(i==0)
                ans.push_back(node->data);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    return ans;
}

int main()
{
    
    return 0;
}