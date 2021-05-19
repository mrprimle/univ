#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> adj[100000];
bool used[100000];

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
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



void dfs(int v, int p = -1) {    //p - parent
    used[v] = true;

    for (int u : adj[v]) {
        if (!used[u]) {
            dfs(u, v);
        }
        else if (u != p) {
            cout << "Graph has cycles.";
            exit(0);
        }
    }
}

int main() {
    // Graph init
    const int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);

    // Check each node because could be unconnected, but has cycles
    for (int i = 0; i < V; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    //if finish loops without exiting - no cycles
    cout << "Graph has no cycles.";
}