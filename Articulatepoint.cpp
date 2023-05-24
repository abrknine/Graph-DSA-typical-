#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>


using namespace std;
void dfs(int node,int parentnode,   
unordered_map<int ,list<int>> &adj,
 vector<int>&disc,
   vector<int> &low,
   vector<int>&ap,
   unordered_map<int,bool> &vis,
   int &timer
){
   visted[node]=true;

   low[node]=dist[node]=timer++;
     int  child=0;
   for(auto neighbour:adj[node]){
         if(neigbour==parent){
          continue;
         }
         if(!visted[neighbour]){

        dfs(nieghbour,node ,adj,disc,low,ap,vis,timer);
          low[node]=min(low[node],low[nieghbour]);

          if(low[nieghbour]>=disc[node] && parent!=-1){
            ap[node]=1;
          }
        child++;

         }

        // case of backedge where a ring kinnda thing form 
        //to usme ye already visted(neigbours) ke dist ko check krta hai agar vo chota hua current node ke low se to low ko update kar deta hai;
         else{
          low[node]=min(low[node], dis[neigbour]);

         }

   }

   if( parent==-1  && child>1){
       ap[node]=1; 
   }


}



int main(){

    int n=5;   
    int e=5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

 

unordered_map<int, list<int>> adj;

for(int i=0; i< edges.size(); i++){
    int  u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
}
   vector<int>disc(n,-1);
   vector<int> low(n,-1);
   vector<int>ap(n,0);//(parent vector) bool hai bhai 0 and 1 me hi lega bs batat hai ki konsi node ap hai 0->nonap ,1->ap
   unordered_map<int,bool>vis;
    int timer=0;  


   for( int i=0; i<n; i++){
     if(!vis[i]){
        dfs(i,-1,adj,disc,low,ap,vis,timer);
     }
   }

      for(int i=0;i<n; i++){
        if(ap[i]!=0){
          cout<<i<<endl;
        }
      }







return 0;
}