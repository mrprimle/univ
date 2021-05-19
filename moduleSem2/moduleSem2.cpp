#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


void inOrder(TreeNode* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->val << endl;
        inOrder(root->right);
    }
}



TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return root;
    }
    TreeNode* op = new TreeNode(root->val);
    op->right = invertTree(root->left);
    op->left = invertTree(root->right);
    return op;
}



int main()
{
    TreeNode* one = new TreeNode;
    TreeNode* two = new TreeNode;
    TreeNode* three = new TreeNode;


    one->val = 1;
    two->val = 2;
    three->val = 3;

    one->left = two;
    one->right = three;


    
    inOrder(one);
    cout << "RESULT: " << endl;
    inOrder(invertTree(one));
}