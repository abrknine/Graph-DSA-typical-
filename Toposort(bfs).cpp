
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
   for( int i=0; i<e; i++){
       int u=edges[i][0];
       int v=edges[i][1];
       adj[u].push_back(v);
   }

  //making indegree vector 
  vector<int> indegree(v);
  for(auto i:adj){ 
      for(auto j:i.second){
          indegree[j]++;
      }
  }
  queue<int> q;
  for( int i=0; i<indegree.size(); i++){
      if(indegree[i]==0){
          q.push(i);
      }
  }
  vector<int> ans;
  while(!q.empty()){

     int front = q.front();
     q.pop();
          ans.push_back(front);
    for(auto neighbour:adj[front]){
      indegree[neighbour]--;
      if(indegree[neighbour]==0){
          q.push(neighbour);

      }


    }



  }

 
     return ans;

    
}