class Solution {
public:

bool isvalid(vector<vector<int>>& image,int oldcolor ,int n, int m  ,int sr, int sc){
    if(sr>=0 && sr<n && sc>=0 && sc<m && image[sr][sc]==oldcolor){
        return true;
    }
    return false;   
}

void dfs(vector<vector<int>>& image,int color ,int n, int m ,int oldcolor ,int sr, int sc){
       image[sr][sc]=color;// imp line in whole algo ur checking moving sr and sc up doen left right if  image[sr][sc]=oldcolor then change it to color
         if(isvalid(image,oldcolor,n,m,sr+1,sc)){

             dfs(image, color, n , m,oldcolor,sr+1,sc);
         }
         if(isvalid(image,oldcolor,n,m,sr,sc+1)){

             dfs(image, color, n , m,oldcolor,sr,sc+1);
         }
         if(isvalid(image,oldcolor,n,m,sr-1,sc)){

             dfs(image, color, n , m,oldcolor,sr-1,sc);
         }
         if(isvalid(image,oldcolor,n,m,sr,sc-1)){

             dfs(image, color, n , m,oldcolor,sr,sc-1);
         }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
       
        int n=image.size();
        int m=image[1].size();
         
         int  oldcolor=image[sr][sc];
         if(oldcolor==color){
             return image;
         }

         dfs(image,color,n,m,oldcolor,sr,sc);
          

      return image;


    }
};