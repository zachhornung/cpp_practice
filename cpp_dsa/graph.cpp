#include <string>
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int v1, int v2){
  adj[v1].push_back(v2);
  adj[v2].push_back(v1);
};

void printGraph(vector<int> adj[], int V){
  for (int i = 0; i < V; i++){
    cout << "\n Adjacency list of vertex " << i << "\n Head";
    for (auto x : adj[i]) cout << "-> " << x << endl;
  }
};

int main(){
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}