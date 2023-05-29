//   algo used to find  no strong component in graph( it only exist in directed graph)
//    that part of graph in which every node can be reacble form every node a graph can have multiple strong component

//    this algo uses stack(used for topo sort) and then  dfs calls acc poping order of elem of stack 

#include <unordered_map>
#include <vector>
#include <list>
#include <stack>

using namespace std;

void ergdfs(unordered_map<int, bool>& vis, unordered_map<int, list<int>>& transpose, int top) {
    vis[top] = true;
    for (auto it : transpose[top]) {
        if (!vis[it]) {
            ergdfs(vis, transpose, it);
        }
    }
}

void dfs(stack<int>& s, unordered_map<int, bool>& vis, int i, unordered_map<int, list<int>>& adj) {
    vis[i] = true;
    for (auto it : adj[i]) {
        if (!vis[it]) {
            dfs(s, vis, it, adj);
        }
    }
    s.push(i);
}

int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    stack<int> s;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(s, vis, i, adj);
        }
    }

    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        vis[i] = false;
        for (auto it : adj[i]) {
            transpose[it].push_back(i);
        }
    }

    int count = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!vis[top]) {
            ergdfs(vis, transpose, top);
            count++;
        }
    }

    return count;
}

