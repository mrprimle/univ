#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void traverseLL(struct Node* n)
{
    while (n != NULL) {
        cout << n->data;
        n = n->next;
    }
}
void traverseLLBack(struct Node* n)
{
    while (n != NULL) {
        cout << n->data;
        n = n->prev;
    }
}

Node* deleteKey(Node* head, int key)
{
    Node* tmp = head;

    while (head->data == key)
    {
        Node* first = head->next;
        Node* second = first->next;
        Node* third = second->next;
        head->next = second;
        second->next = first;
        first->next = third;
        second->prev = head;
        first->prev = second;
        third->prev = first;
        head = second;
    }
    while (tmp->next != NULL)
    {
        if (tmp->next->data == key)
        {
            Node* first = tmp->next->next;
            Node* second = first->next;
            Node* third = second->next;
            tmp->next = second;
            second->next = first;
            first->next = third;
            second->prev = tmp;
            first->prev = second;
            third->prev = first;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return head;
}


int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    Node* fifth = new Node;


    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = fourth;
    third->prev = second;

    fourth->data = 8;
    fourth->next = fifth;
    fourth->prev = third;

    fifth->data = 5;
    fifth->next = NULL;
    fifth->prev = fourth;







    traverseLL(head);
    cout << endl << "Result:" << endl;
    traverseLL(deleteKey(head, 2));
    cout << endl << "Result backwards (to check pointers):" << endl;
    traverseLLBack(fifth);

    return 0;
}