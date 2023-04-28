#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template <typename T>

class graph {
    public:
      unordered_map<T, list<T>>adj;
      void addEdge(T u, T v, bool direction){
               //direction=0->undirected graph
               //direction=1-> directed graph
               //create an edge from u to v
               adj[u].push_back(v);
               if(direction==0){
                adj[v].push_back(u);
               }
      }
      void printadjlist(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<endl;
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
     g.addEdge(2,5,2);
     g.addEdge(3,4,-1);
     g.addEdge(4,5,-2);

     g.print()

    int n; // no of nodes
    cin>>n;
    int m;
    cin>>m ;// no of edges

    graph<int> g;
    //GIVING NODES THAT ARE CONNECTED u AND v
    for(int i=0; i<m ; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0); //undirected graph

    }
        g.printadjlist();

return 0;
}