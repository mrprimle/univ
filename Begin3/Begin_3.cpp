#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* A binary tree node has data,
pointer to left child and a
pointer to right child */

struct NodeData {
    string en;
    string ru;
    int counter;
};

struct Node
{
    NodeData data;
    Node* left, * right;
};

/* Helper function that allocates a
new node */
Node* newNode(NodeData data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

// Function to insert nodes in level order
Node* insertLevelOrder(vector<NodeData*> arr, Node* root,
    int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        Node* temp = newNode(*arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr,
            root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr,
            root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to print tree nodes in
// InOrder fashion
void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data.en << " " << root->data.ru << " " << root->data.counter << endl;
        inOrder(root->right);
    }
}

void searchInorder(Node* root, string word)
{
    if (root != NULL)
    {
        searchInorder(root->left, word);
        //cout << root->data.en << " " << root->data.ru << " " << root->data.counter << endl;
        if (root->data.en == word) {
            cout << root->data.ru << endl;
            root->data.counter++;
            return;
        }
        searchInorder(root->right, word);
    }
}

// Driver program to test above function
int main()
{
    /*NodeData* one = new NodeData;
    NodeData* two = new NodeData;
    NodeData* three = new NodeData;


    one->en = "dog";
    one->ru = "sobaka";
    one->counter = 1;

    two->en = "yes";
    two->ru = "dah";
    two->counter = 2;

    three->en = "no";
    three->ru = "nett";
    three->counter = 5;*/

    vector <NodeData*> nodes;
    while (true) {
        NodeData* node = new NodeData;
        string firstInp;
        cout << "Enter english word: ";

        // check for exit
        cin >> firstInp;
        if (firstInp == "0") {
            cout << "\n";
            break;
        }

        node->en = firstInp;
        cout << "Enter russian translation: ";
        cin >> node->ru;
        cout << "Enter the counter: ";
        cin >> node->counter;

        nodes.push_back(node);
    }

    /*nodes.push_back(one);
    nodes.push_back(two);
    nodes.push_back(three);*/



    int n = nodes.size();
    Node* root = insertLevelOrder(nodes, NULL, 0, n);
    inOrder(root);

    cout << endl << "Dictionary is ready, enter the word to translate." << endl;
    while (true) {
        string firstInp;
        cout << "Enter english word: ";

        // check for exit
        cin >> firstInp;
        if (firstInp == "0") {
            cout << "\n";
            break;
        }

        searchInorder(root, firstInp);
    }
    cout << "Final Tree:" << endl;
    inOrder(root);
}
