#include<unordered_map>
#include <list>


 bool dfscyclicdetectiondirected(unordered_map<int, bool>& visited, int srcnode,
        unordered_map<int, bool> &dfsvisited, unordered_map<int,list<int>> &adj)
 {
   visited[srcnode]=true;
   dfsvisited[srcnode]=true;
   for( auto nieghbours:adj[srcnode]){
     if(!visited[nieghbours]){
       bool a=dfscyclicdetectiondirected(visited, nieghbours, dfsvisited, adj );
         if(a){
           return true;
         }
     }
     else if(dfsvisited[nieghbours]){
       return true;
     }
   }
   dfsvisited[srcnode]=false;
   return false;
 }
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
     unordered_map<int,list<int>> adj;
      for( int i=0 ;i<edges.size(); i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
         //this is direscted graph    
      } 
         unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;
      for( int i=0; i<n; i++){
        if(!visited[i]){
     bool ans= dfscyclicdetectiondirected(visited,i,dfsvisited, adj );
       if(ans){
    return true;
  }
        }
      }
return false;
}