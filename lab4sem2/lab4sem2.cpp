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

// Function to build Expression Tree
nptr build(string& s)
{

    // Stack to hold nodes
    stack<nptr> stN;

    // Stack to hold operands
    stack<char> stC;
    nptr t, t1, t2;

    // Prioritising the operators
    int p[123] = { 0 };
    p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
        p[')'] = 0;

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
                && ((s[i] != '^' && p[stC.top()] >= p[s[i]])
                    || (s[i] == '^'
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
char isDigit(char p) {
    if (p >= '0' && p <= '9') return 1;
    else return 0;
}

int isOperator(char p) {
    if (p == '+' || p == '-' || p == '*' || p == '/') return 1;
    else return 0;
}

int charToDigit(char p) {
    if (p >= '0' && p <= '9') return p - '0';
    else return 0;
}

int performOperator(int a, int b, char p) {
    switch (p) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) { printf("Can't divide by 0, aborting...\n"); exit(1); }  // now we dont want the world to expload here do we.
        return a / b;
    default:
        puts("Bad value in switch.\n"); // A replacement which was mentioned in the thread- better have a default response just in case something goes wrong.
        break;
    }
    return 0;
}



// Driver code
int main()
{
    string s = "3+5+7*3*2";
    s = "(" + s;
    s += ")";

    // build tree
    nptr root = build(s);

    // print tree
    postorder(root);
    cout << res << endl << endl;

    struct StackNode* stackRoot = NULL;

    for (char val : res) {
        if (isDigit(val)) {
            //cout << "digit";
            if (isOperator(peek(stackRoot))) {
                //cout << "oper prev";
                push(&stackRoot, charToDigit(val));
            }
            else if (isDigit(peek(stackRoot))) {
                //cout << "digit prev";
                int prevNum = charToDigit(pop(&stackRoot));
                push(&stackRoot, prevNum * 10 + charToDigit(val));
            }
            else {
                push(&stackRoot, charToDigit(val));
            }
        }
        else if (isOperator(val)) {
            //cout << "oper";
            int num1 = pop(&stackRoot);
            int num2 = pop(&stackRoot);
            push(&stackRoot, performOperator(num1, num2, val));
        }
    }


    printf("Top element is %d\n", peek(stackRoot));

    return 0;
}