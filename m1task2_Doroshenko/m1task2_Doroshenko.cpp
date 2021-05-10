#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Node {
    int data;
    struct Node* next;
};


void printLL(struct Node* n) {
    while (n != NULL) {
        cout << n->data << ' ';
        n = n->next;
    }
    cout << "\n";
}

Node* traverseLL(struct Node* n) {
    // edge case
    if (n == NULL) {
        //cout << "done (nothing in the List)";
        return n;
    }
    else {
        Node* dummy = new Node;
        dummy->data = 1;
        dummy->next = n;
        while (n->next != NULL) {
            Node* n2 = n->next;
            if (n->data == n2->data) {
                Node* temp = n2->next;
                n2->next = NULL;
                n->next = temp;
            }
            else {
                n = n->next;
                n2 = n2->next;
            }
        }
        return dummy->next;
    }
}


int main()
{


    // allocate 5 nodes in the heap 
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    Node* fifth = new Node;


    head->data = 1; 
    head->next = second; 

    second->data = 1; 
    second->next = third;

    third->data = 2; 
    third->next = fourth;

    fourth->data = 2; 
    fourth->next = fifth;

    fifth->data = 3; 
    fifth->next = NULL;


    printLL(head);
    printLL(traverseLL(head));


    return 0;
}
