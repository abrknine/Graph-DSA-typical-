#include<iostream>
using namespace std;
void()
int main(){

    int n=5;
    int e=5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

 

unordered_map<int list<int>> adj;

for(int i=0; i<edges.size(); i++){
    int  u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
}
   vector<int>disc(n,-1);
   vector<int>low(n,-1);
   vector<int>ap(n,0);
   unordered_map<int,bool>vis;
   timer=0;


   for( int i=0; i<n; i++){
     if(!vis[i]){
        dfs(i,-1,adj,disc,low,ap,vis,timer)
     }
   }







return 0;
}