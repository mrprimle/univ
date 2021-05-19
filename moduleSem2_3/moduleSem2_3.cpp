#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Tree Structure
typedef struct node
{
    char data;
    struct node* left, * right;
} *nptr;

// Function to create new node
nptr newNode(char c)
{
    nptr n = new node;
    n->data = c;
    n->left = n->right = nullptr;
    return n;
}

// build expression Tree
nptr build(string& s)
{
    stack<nptr> stN;

    // Stack to hold operands
    stack<char> stC;
    nptr t, t1, t2;

    // prioritising the operators
    int p[999] = { 0 };
    p['&'] = p['|'] = 1, p['-'] = 2, p[')'] = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') {

            // Push '(' in char stack
            stC.push(s[i]);
        }

        // Push the operands in node stack
        else if (isalpha(s[i]) || isdigit(s[i]))
        {
            t = newNode(s[i]);
            stN.push(t);
        }
        else if (p[s[i]] > 0)
        {
            // If an operator with lower or
            // same associativity appears
            while (
                !stC.empty() && stC.top() != '('
                && ((s[i] != '-' && p[stC.top()] >= p[s[i]])
                    || (s[i] == '-'
                        && p[stC.top()] > p[s[i]])))
            {

                // Get and remove the top element
                // from the character stack
                t = newNode(stC.top());
                stC.pop();

                // Get and remove the top element
                // from the node stack
                t1 = stN.top();
                stN.pop();

                // Get and remove the currently top
                // element from the node stack
                t2 = stN.top();
                stN.pop();

                // Update the tree
                t->left = t2;
                t->right = t1;

                // Push the node to the node stack
                stN.push(t);
            }

            // Push s[i] to char stack
            stC.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!stC.empty() && stC.top() != '(')
            {
                t = newNode(stC.top());
                stC.pop();
                t1 = stN.top();
                stN.pop();
                t2 = stN.top();
                stN.pop();
                t->left = t2;
                t->right = t1;
                stN.push(t);
            }
            stC.pop();
        }
    }
    t = stN.top();
    return t;
}

// Function to print the post order
// traversal of the tree
string res = "";
void postorder(nptr root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        //cout << root->data;
        res += root->data;
    }
}







// Stack implementation
struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode =
        (struct StackNode*)
        malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root)
{
    return !root;
}

void push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    printf("%d poped from stack\n", popped);
    return popped;
}

int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}





// helper func
int charToDigit(char p) {
    if (p >= '0' && p <= '9') return p - '0';
    else return 0;
}

int performOperator(int a, int b, char p) {
    switch (p) {
    case '&': return (a && b);
    case '|': return (a || b);
    }
}

string normString(string s) {
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            if (s[i + 1] == '0') {
                temp += '1';
            }
            else if (s[i + 1] == '1') {
                temp += '0';
            }
            else {
                temp += s[i + 1];
            }
            i++;
        }
        else {
            temp += s[i];
        }
    }
    s = temp;
    return s;
}

vector<string> ress = {};
vector<string> reqDeterm(string s, string temp, int j, vector<string> res) {
    for (j; j < s.length(); j++) {
        if ((temp + ')').length() == s.length()) {
            //cout << temp << endl;
            ress.push_back(temp + ')');
        }
        if (isalpha(s[j])) {
            reqDeterm(s, temp + '0', j + 1, res);
            reqDeterm(s, temp + '1', j + 1, res);
        }
        else {
            temp += s[j];
        }
    }
    return res;
}

void calcBin(string s) {
    struct StackNode* stackRoot = NULL;

    for (char val : s) {
        if (val == '1' || val == '0') {
            push(&stackRoot, charToDigit(val));
        }
        else {
            int num1 = pop(&stackRoot);
            int num2 = pop(&stackRoot);
            push(&stackRoot, performOperator(num1, num2, val));
        }
    }


    printf("Top element is %d\n", peek(stackRoot));
}


// Driver code
int main()
{
    //string s = "1&-0|0|s&-q";
    string s = "1&-0|a|(0&-b)";
    s = "(" + s;
    s += ")";

    string normS = normString(s);
    cout << normS << endl;

    vector<string> detS = reqDeterm(normS, "", 0, {});
    cout << endl << endl;
    for (auto st : ress) {
        // build tree
        nptr root = build(st);

        // print tree
        postorder(root);
        cout << res << endl;
        calcBin(res);
        cout << endl << endl;
        res = "";
    }


    

    return 0;
}