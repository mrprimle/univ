#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// node of binary tree
struct Node
{
    int data;
    Node* lptr;
    Node* rptr;
};

int findLevel(Node* root, Node* ptr, int level = 0)
{
    if (root == NULL)
        return -1;
    if (root == ptr)
        return level;
    // If NULL or leaf Node
    if (root->lptr == NULL && root->rptr == NULL)
        return -1;
    // Find If ptr is present in the left or right subtree.
    int levelLeft = findLevel(root->lptr, ptr, level + 1);
    int levelRight = findLevel(root->rptr, ptr, level + 1);
    if (levelLeft == -1)
        return levelRight;
    else
        return levelLeft;
}

int main()
{
    // create a binary tree
    Node* root = new Node(20);
    root->left = getnode(10);
    root->right = getnode(30);
    root->left->left = getnode(5);
    root->left->right = getnode(15);
    root->left->right->left = getnode(12);
    root->right->left = getnode(25);
    root->right->right = getnode(40);

    // return level of node
    int level = getlevel(root, 30);
    (level != 0) ? (cout << "level of node 30 is " << level << endl) :
        (cout << "node 30 not found" << endl);

    level = getlevel(root, 12);
    (level != 0) ? (cout << "level of node 12 is " << level << endl) :
        (cout << "node 12 not found" << endl);

    level = getlevel(root, 25);
    (level != 0) ? (cout << "level of node 25 is " << level << endl) :
        (cout << "node 25 not found" << endl);

    level = getlevel(root, 27);
    (level != 0) ? (cout << "level of node 27 is " << level << endl) :
        (cout << "node 27 not found" << endl);
    return 0;
}