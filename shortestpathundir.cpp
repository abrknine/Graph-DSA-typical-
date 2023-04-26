#include<list>
#include<unordered_map>
#include<queue>
#include<vector>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int, list<int>> adj;
	for ( int i=0; i<edges.size(); i++){
		int u=edges[i].first;
		int v=edges[i].second;

       adj[u].push_back(v);
	   adj[v].push_back(u);
	}


	unordered_map<int,bool> visited;
     unordered_map<int,int> parent;

	 queue<int> q;
	 q.push(s);
	 visited[s]=true;
	 parent[s]=-1;

	 while(!q.empty()){
      int front=q.front();
	  q.pop();

    for( auto neighbours:adj[front]){
      if (!visited[neighbours]) {
        visited[neighbours] = true;
        parent[neighbours] = front;
        q.push(neighbours);
      }
    }
         }


   vector<int> ans;
   int currentNode=t;
   ans.push_back(currentNode);
   while (currentNode != s) {
     currentNode = parent[currentNode];
     ans.push_back(currentNode);
   }
   reverse(ans.begin(), ans.end());
   return ans;
         
}