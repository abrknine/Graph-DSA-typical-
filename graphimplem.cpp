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
                cout<<j<<",";
            }
            cout<<endl;
        }
        

      }
};

int main(){

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