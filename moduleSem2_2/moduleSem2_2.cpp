#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* left, * right;
};


void findCurrentLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);



// Finds the level above the mid level and checks it's childs
void findCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1) {
        if (root->left != NULL && height(root->left->left) == height(root->left->right)) {
            root->left = NULL;
        }
        if (root->right != NULL && height(root->right->left) == height(root->right->right)) {
            root->right = NULL;
        }
    }
    else if (level > 1)
    {
        findCurrentLevel(root->left, level - 1);
        findCurrentLevel(root->right, level - 1);
    }
}


int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}


struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}


void inOrder(node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << endl;
        inOrder(root->right);
    }
}




int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->left->right->right = newNode(6);


    inOrder(root);
    int midLevel = (height(root) - 1) / 2;
    findCurrentLevel(root, midLevel);
    cout << "RESULT: " << endl;
    inOrder(root);

    return 0;
}
