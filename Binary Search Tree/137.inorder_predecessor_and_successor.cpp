#include <bits/stdc++.h>
using namespace std;

// There is BST given with root node with key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

struct Node
{
	int key;
	struct Node *left, *right;
};

void findpre(Node *root, Node *&pre, int key)
{
    pre = NULL;
    while (root)
    {
        if (root->key < key)
        {
            pre = root;
            root = root->right;
        }
        else
            root = root->left;
    }
}
void findsuc(Node *root, Node *&suc, int key)
{
    suc = NULL;
    while (root)
    {
        if (root->key > key)
        {
            suc = root;
            root = root->left;
        }
        else
            root = root->right;
    }
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    findpre(root, pre, key);
    findsuc(root, suc, key);
}

int main()
{

    return 0;
}