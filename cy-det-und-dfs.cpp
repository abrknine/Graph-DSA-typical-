
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>



 
 bool iscyclicdfs(unordered_map<int, bool>  &visited,int srcnode, int parent ,unordered_map<int , list<int>> &adj)
{
    visited[srcnode]=true;

       for( auto neighbour: adj[srcnode] ){  /* use this kindda loop for map of int and list or 2d vector*/
          if(!visited[neighbour]){

               bool cycledetected=iscyclicdfs(visited, neighbour, srcnode, adj  );
 
               if(cycledetected){
                   return true;
               }
          }
        
         else  if(neighbour!=parent){
              return true;
          }





       }
       return  false;
    

}




string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    unordered_map<int , list<int>> adj;
    for( int i=0; i<m; i++){
        int u= edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    unordered_map<int, bool> visited;

    for( int i=0; i<n; i++){
        if(!visited[i]){
            bool ans= iscyclicdfs(visited,i, -1,adj);
            if(ans==1){
                return "Yes";
            }
        }
    }

    return "No";
}

