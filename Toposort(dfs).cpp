//#include <bits/stdc++.h>        
#include<unordered_map>
#include<vector>
#include<stack>
#include<list>

void topo(int srcnode, vector<bool>& visited,unordered_map<int, list<int>>& adj, stack<int>& s)
 {
    visited[srcnode]=true;
    for(auto neighbour:adj[srcnode]){
        if(!visited[neighbour]){

        topo(neighbour,visited,adj,s);
        }
    }
    s.push(srcnode);
 }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

   // make adjacency  map       
    unordered_map<int, list<int>> adj;
    for( int i=0; i<e; i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

   vector<bool> visited(v,false);
   stack<int> s;
   for(int i=0; i<v; i++)
{
    if(!visited[i]){
        topo(i, visited,adj,s);
    }
}

   vector<int> ans;

   while(!s.empty()){
       ans.push_back(s.top());
       s.pop();
   }

   return ans;



}
