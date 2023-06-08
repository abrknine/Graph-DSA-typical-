 #include<algorithm>
 bool cmp(vector<int>&a, vector<int>&b){
  return a[2]<b[2];
 }

 //this function returns parent of any node by uptraveseing in graph 

 int findparent(vector<int> &parent,int node
){
    if(parent[node]==node){
      return node;
    }

    return parent[node]=findparent(parent,parent[node]);
}
 
 
 // this just initilaising  parent and rank vector
 void makeSet(vector<int> &parent, vector<int> &rank,int n){
      for( int i=0; i<n; i++)
      {
        parent[i]=i;
        rank[i]=0;
      }
 }

// this function update parent and rank array
 void unionset(int u, int v,vector<int> &parent, vector<int> &rank){
      u=findparent(parent,u);
       v=findparent(parent,v);

      if(rank[u]<rank[v]){   //rank kam mtlb choti height ka tree
        parent[u]=v;        // and we always merge small tree to big so height remain same;
      }
      else if (rank[v]>rank[u]){
           parent[v]=u;
      }
      else{
        parent[u]=v;
        rank[u]++;
      }


 }

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
   vector<int> parent(n);
   vector<int> rank(n);// this array gonna contain 
   makeSet(parent, rank,n); // mtlb parent and rank array ko algo ke acc bana diya; rank ke elem 0 kar diye aur parent ke elem uske index kardiye
    
  int minwt=0;
    sort(edges.begin(),edges.end(),cmp);

    for( int i=0; i<edges.size(); i++){
      int u=findparent(parent,edges[i][0]);
      int v=findparent(parent,edges[i][1]);
      int w=edges[i][2];

      if(u!=v){
        //mean they are in diff component then make both together or union them (using small tree merge to big tree rule ->union function)
        minwt=minwt+w;
        unionset( u, v,parent, rank);

      }

    }
  // here we also can make mst using parent vector cuz we have parent to every other node ;
return minwt;

    
     
}