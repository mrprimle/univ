#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V) {
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex "
            << v << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}
// Helper in func
bool in(vector<int> arr[], int key) {
    for (auto i = arr->begin(); i != arr->end(); ++i) {
        if (*i == key) {
            return true;
        }
    }
    return false;
}

int inArr(int val, int* arr[]) {
    for (int i = 0; i < sizeof(*arr[]); i++) {
        if (*arr[i] == val) return 1;
    }
    return 0;
}



// 1
void mergeNodes(vector<int> adj[], int n1, int n2) {
    vector<int> connections = {};
    for (auto x : adj[n1]) {
        if (x != n2) {
            connections.push_back(x);
        }
    }

    for (auto x : adj[n2]) {
        if (!in(&connections, x) && x != n1) {
            connections.push_back(x);
        }
    }

    adj[n1] = {};
    for (auto i = (&connections)->begin(); i != (&connections)->end(); ++i) {
        if (!(inArr(*(adj[n1]), *i)) && *i != n1) {
            addEdge(adj, n1, *i);
        }
    }
    printGraph(adj, 5);
    //adj->erase(adj->begin() + n2);

    //printGraph(adj, 5);
}


int main()
{
    // Read file and build an Adjacency Matrix representation of Graph
    ifstream input("graphInp.txt");

    const int V = 5;
    vector<int> adj[V];

    int lineCount = -1;
    for (string line; getline(input, line); ) {
        lineCount++;
        for (auto c : line) {
            int node = c - '0';
            addEdge(adj, lineCount, node);
        }
    }
    printGraph(adj, V);

    mergeNodes(adj, 1, 2);


    /*const int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);*/
    return 0;
}