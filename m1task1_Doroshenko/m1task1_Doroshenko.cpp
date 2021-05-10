#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

// stack implementation
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




int main()
{
    struct StackNode* root = NULL;

    
    // CREATE file
    ofstream f("inp.txt");
    char A[5] = {'1', '2', '+', '6', '*'};
    for (int i = 0; i < 5; i++)
    {
        f << A[i];
    }
    f.close();

    
    // iter chars
    ifstream f1("inp.txt");
    char val;
    for (int i = 0; i < 5; i++)
    {
        f1 >> val;

        if (isDigit(val)) {
            //cout << "digit";
            if (isOperator(peek(root))) {
                //cout << "oper prev";
                push(&root, charToDigit(val));
            }
            else if (isDigit(peek(root))){
                //cout << "digit prev";
                int prevNum = charToDigit(pop(&root));
                push(&root, prevNum * 10 + charToDigit(val));
            }
            else {
                push(&root, charToDigit(val));
            }
        }
        else if (isOperator(val)) {
            //cout << "oper";
            int num1 = pop(&root);
            int num2 = pop(&root);
            push(&root, performOperator(num1, num2, val));
        }
    }


    printf("Top element is %d\n", peek(root));


    //push(&root, 10);
    //pop(&root);
    //printf("Top element is %d\n", peek(root));


    return 0;
}