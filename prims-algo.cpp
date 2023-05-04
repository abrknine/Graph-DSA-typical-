// prims algo is used to fing mst ( minimum spanning tree)
//prim's algo is ude to find the minimum spanning tree of graph
//it gernally retrun the vector i with every  indec is node ans its element is parent to tat node then we can make a tree out of it  with is 
 //spanning tree -> tree in graph which contain n( no of nodes in graph too) nodes and n-1 edges and every node is reachable from every node
 //MST-> ST eith Minimum weight is MST


#include<unordered_map>
#include<list>
#include<vector>
#include<climits>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int,int>>> adj;

    for( int i=0; i<g.size(); i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w =g[i].second;


   /* adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));*/
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    }

    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

   

      key[1]=0;
      

      for( int i=0; i<n-1; i++){
         int min=INT_MAX;
         int u;
         for( int v=1; v<=n; v++){
             if(key[v]<min && mst[v]==false){
                 min=key[v];
                 u=v;
             }
         }
         mst[u]=true;

      for( auto it: adj[u]){
          int weight=it.second;
          int  neinode=it.first;

         if(mst[neinode]==false && weight<key[neinode]){
             key[neinode]=weight;
             parent[neinode]=u; // u ke hi to baccho me me travese karra hu o parent me jaha jaha par u ke bacche hai waha u dal de
         }
      }
      }
      vector<pair<pair<int, int>, int>> a;

     for( int i=2; i<=n ;i++){
         a.push_back(make_pair(make_pair(parent[i], i),key[i]));
     }
     return a;





}


