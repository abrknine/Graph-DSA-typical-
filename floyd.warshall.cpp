 //floyd warshall return a matrix in with row and col mean node of tree and elem in that matrix at specific [row][col]=min dist btw that two nodes( as row and col representing nodes of graph)
   //neeche hamne vo matrix banaye pehle phir  do given nodes  ka min dist output kar diya 
   //works on -ve graph also
   //its given that there is no -ve cylce wran tu uska case likh ke cout kara deta ki esme to shortest apth ho hi nhi sakta kyki -ve cycle hai
#include<climits>
#include<vector>
        int floydWarshall(int n, int m, int src, int dest,
         vector<vector<int>> &edges) {
        // Write your code here.
        int matrix[n+1][n+1];
        for(int i=1; i<=n; i++){
            for( int j=1; j<=n; j++){
                    matrix[i][j] = INT_MAX;
                if(i==j){
                    matrix[i][j]=0;
                }
            }
        }
        for (int i=0; i<m; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
                matrix[u][v]=w;
        }

        for( int k=1;k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if ( i!=k && j!=k && matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                        }
                
                }
            }
        }
 return matrix[src][dest]==INT_MAX?1e9:matrix[src][dest];

        }
