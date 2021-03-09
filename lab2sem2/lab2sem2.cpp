#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Node {
    vector<string> data;
    struct Node* next;
};






string multiply(string x, string y) {
    string res = "00000000";
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '1' && y[i] == '1') {
            res[i] = '1';
        }
        else {
            res[i] = '0';
        }
    }
    return res;
}


string pluss(string x, string y) {
    string res = "00000000";
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '1' || y[i] == '1') {
            res[i] = '1';
        }
        else {
            res[i] = '0';
        }
    }
    return res;
}


string arrayPlus(vector<string> arr) {
    if (arr.size() == 1) {
        return arr[0];
    }
    else {
        for (int i = 0; i < arr.size() - 1; i++) {
            string vec = pluss(arr[i], arr[i + 1]);
            arr[i + 1] = vec;

        }
        return arr[arr.size() - 1];
    }



}




string arrayMul(vector<string> arr) {
    if (arr.size() == 1) {
        return arr[0];
    }
    else {
        for (int i = 0; i < arr.size() - 1; i++) {
            string vec = multiply(arr[i], arr[i + 1]);
            arr[i + 1] = vec;

        }
        return arr[arr.size() - 1];
    }



}




vector<string> normArray(vector<string> arr) {
    vector<string> res = {};
    for (auto elem : arr) {
        if (elem.size() == 1) {
            if (elem == "x") {
                res.push_back("00001111");
            }
            else if (elem == "y") {
                res.push_back("00110011");
            }
            else {
                res.push_back("01010101");
            }
        }
        else {
            if (elem[1] == 'x') {
                res.push_back("11110000");
            }
            else if (elem[1] == 'y') {
                res.push_back("11001100");
            }
            else {
                res.push_back("10101010");
            }
        }
    }
    return res;
}



string traverseLL(struct Node* n)
{
    vector<string> itemsToPlus = {};
    while (n != NULL) {
        itemsToPlus.push_back(arrayMul(normArray(n->data)));
        n = n->next;
    }
    return arrayPlus(itemsToPlus);
}

int main()
{
    

    // allocate 3 nodes in the heap 
    Node * head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    

    head->data = {"x", "y", "z"}; // assign data in first node 
    head->next = second; // Link first node with second 

    second->data = { "x", "~y"}; // assign data to second node 
    second->next = third;

    third->data = {"z"}; // assign data to third node 
    third->next = NULL;







    cout << traverseLL(head);

    return 0;
}