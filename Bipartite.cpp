bipartite graph is graph whose every other node can be put in other set and both set dont have any link within set element
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
   int n=graph.size();

   vector<int>color(n,0);
   for( int i=0; i<n; i++){
       if(color[i]==1 || color[i]==-1){
           continue;
       }
       color[i]=1;
       queue<int> q;
       q.push(i);
       while(!q.empty()){
           int curr=q.front();
           q.pop();

             for(int next:graph[curr]){
             
           if(color[next]==0){
               color[next]=-color[curr];
               q.push(next);
               
           }
       if(color[next]==color[curr]){
           return false;
       }
       }



       }

     

   }
   return true;


    }
};