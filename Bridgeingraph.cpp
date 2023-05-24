
//brides is edges after removing that or graph is converted into two component

// to find no of bridges 
// we take  tim and low vector
// tim vector stores the no of timth dfs call has to make to reach the node
// low vector check all the neighbour execpt parent to curr node and fill it up with samellest  low[neigbours];
// we use both vecotor to find no of bridges
// we make dfs call and while returning of call we check for bridges

// do this ques 2-3 time again n again 


class Solution {
public:
int timer=1;
  void  dfs(int node , int parent,  vector<int> adj[],int tim[], int low[], vector<int>&visited, vector<vector<int>>& bridges ){
      visited[node]=1;
      tim[node]=low[node]=timer;
      timer++;

      for( auto it:adj[node] ){
          if( it==parent){
              continue;
          }
          if(visited[it]==0){
              dfs(it,node,adj,tim,low,visited,bridges);
        // call ke baad cheeeje likhne ka mtlb hai ki base point hit krne ke baad ab vo backtrack hori hai
              low[node]=min(low[node],low[it]); 
              if(low[it]>tim[node]){
                  bridges.push_back({node,it});
              }
          }
          else{
              low[node]=min(low[node],low[it]);
          }

      }

  }



    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        

        vector<int> adj[n];
        for( auto it:connections){
            int a=it[0];
            int b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int>visited(n,0);
        int tim[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0,-1,adj,tim,low,visited,bridges);
        return bridges;
    }
};