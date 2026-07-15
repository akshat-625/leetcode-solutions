class Solution {
public:
    void dfs(vector<vector<int>>& image,int i, int j, int newColor, int orgColor ){
       int n = image.size() ; //row size
       int m = image[0].size() ; //column size

       //Base Case
       if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] != orgColor || image[i][j] == newColor){
           
           return ;
       } 

       //Change the starting given cell to new color
       image[i][j] = newColor ;

       //Check in all the four directions :
       dfs(image, i-1, j, newColor, orgColor) ;
       dfs(image, i+1, j, newColor, orgColor) ;
       dfs(image, i, j+1, newColor, orgColor) ;
       dfs(image, i, j-1, newColor, orgColor) ;


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //func. call to dfs
        dfs(image,sr,sc,color,image[sr][sc]) ;
        
 
        return image ; //very important to return the ans. image[][]

    }
};