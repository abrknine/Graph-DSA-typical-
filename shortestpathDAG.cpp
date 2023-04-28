 //ques 
 //find the shortest path from source node to every other node in graph ( you can return vector where each elem is shortest path of the node of graph(index of that array) form src node)

#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include <climits>
#include<cmath>

using namespace std;
class  Graph{
  public:

  unordered_map<int,list<pair<int,int>>> adj;

  void addEdge(int u , int v, int weight){
    pair<int,int> p=make_pair(v, weight);
    adj[u].push_back(p);
  }

 void printAdj(){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<"{"<<j.first<<","<<j.second<<"),";
        }
        cout<<endl;
    }
 }

  void dfs( int srcnode,unordered_map<int,bool>& vis,stack<int> &s){
            vis[srcnode]=true;

            for(auto neighbours:adj[srcnode]){
                if(!vis[neighbours.first]){
                    dfs(neighbours.first,vis,s);
                }
            }

     s.push(srcnode);
        

     }

     void shortestPath(int src,vector<int> &dist,stack<int> &s){
           dist[src]=0;
            while(!s.empty()){
                int top=s.top();
                s.pop();

                if(dist[top]!=INT_MAX){
                  for(auto i:adj[top]){
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first]=dist[top]+i.second;
                    }
                      
                                       }


                }
          

            }


     }
};
int main(){
     Graph g;
     g.addEdge(0,1,5);
     g.addEdge(0,2,3);
     g.addEdge(1,2,2);
     g.addEdge(1,3,6);
     g.addEdge(2,3,7);
     g.addEdge(2,4,4);
     g.addEdge(3,4,-1);
     g.addEdge(4,5,-2);
     g.printAdj();
     int n=6;

     unordered_map<int,bool> vis;
     stack<int> s;
     for( int i=0; i<n ; i++){
        if(!vis[i]){
            g.dfs(i,vis,s);
        }
     }
    int src=1;
     vector<int> dist(n);
     for( int i=0; i<n; i++){
        dist[i]=INT_MAX;
     }

     g.shortestPath(src,dist,s);
    cout<<" shortest paths from src=1 to all other node"<<endl;

     for( int i=0;i<n; i++)
{
    cout<<dist[i]<<" ";
}
cout<<endl;



return 0;
}