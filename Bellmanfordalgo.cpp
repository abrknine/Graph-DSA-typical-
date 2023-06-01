// Applied to find shoetest dist form  given node to other given node 
//Applied to directed graphs only(mostly)
// IF GRAPH HAS negative edge then use this 
// it can't be used if graph has negative cycle ( in negative cyle there is no shortest path cuz due to negative cyle in every round path became shortest)
//so  1) it can tell if graph has -ve cycle or not and 2) shortest dist in graph having -ve edges


#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.

    vector<int> dis(n+1,1e9);
    dis[src]=0;

   for(int i=1; i<=n-1; i++){
    for( int j=0; j<m; j++){
        int u=edges[j][0];
         int v=edges[j][1];
        int w=edges[j][2];

        if(dis[u]!=1e9 &&( (dis[u]+w)<(dis[v]))){
            dis[v]=dis[u]+w;
        }
    }

   }


 // check of -ve cylce//
   bool flag=0;
    for( int j=0; j<m; j++){
        int u=edges[j][0];
         int v=edges[j][1];
        int w=edges[j][2];
       if(dis[u]!=1e9 &&((dis[u]+w)<(dis[v]))){
            flag=1;
        }
    }

    if(flag==0){
        return dis[dest];
    }
    return -1;
           

 



  }