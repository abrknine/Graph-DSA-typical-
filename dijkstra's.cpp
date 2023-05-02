
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<limits>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.

    //making adj graph
   unordered_map<int,list<pair<int, int>>> adj;

   for(int i=0; i<edges; i++)
   {
       int u=vec[i][0];
       int v=vec[i][1];
       int w=vec[i][2];

      adj[u].push_back(make_pair(v,w));
      adj[v].push_back(make_pair(u,w));

   }


   vector<int> dist(vertices);
   for( int i=0; i<vertices; i++){
       dist[i]=INT_MAX;
   }
   set<pair<int, int>> s;
   dist[source]=0;
   s.insert(make_pair(0,source));

   while(!s.empty()){
       auto a=*(s.begin());

       int  nodedist=a.first;
       int  topnode=a.second;

       s.erase(s.begin());

       for(auto neighbours:adj[topnode]){
         
         if(nodedist+neighbours.second<dist[neighbours.first]){
          
          auto b=s.find(make_pair(dist[neighbours.first],neighbours.first));

          if(b!=s.end()){
             // s.erase(make_pair(dist[neighbours.first],neighbours.first))
            s.erase(b);

          }
          dist[neighbours.first]= nodedist+neighbours.second;
          s.insert(make_pair(dist[neighbours.first],neighbours.first));

         }
       


       }

    
   }
   

   

return dist;

}