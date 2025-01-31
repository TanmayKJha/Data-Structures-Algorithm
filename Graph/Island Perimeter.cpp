//USING DFS
//Time Complexity O(m * n) //Space Complexity: O(m * n)
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i , int j, int m, int n, vector<vector<bool>>&visited){
        vector<vector<int>>directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int side = 0;
        for(auto &dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];

            if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==0){
               side+=1 ;
            }else if(grid[x][y]==1 && !visited[x][y]){
                visited[x][y]= true;
                side+=dfs(grid,x,y,m,n,visited);
            }
        }
        return side;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    visited[i][j]=true;
                    perimeter+=dfs(grid,i,j,m,n,visited);
                }
            }
        }
        return perimeter;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//USING MATRIX TRAVERSAL
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size();
        int n =grid[0].size();
        int perimeter = 0;
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0){
                    continue;
                //grid[i][j]==1
                //checks all the directions
                }else{ 
                if(j-1<0 ||grid[i][j-1]==0){
                    perimeter+=1;
                }
                if(j+1>=n ||grid[i][j+1]==0){
                    perimeter+=1;
                }
                if(i+1>=m ||grid[i+1][j]==0){
                    perimeter+=1;
                }
                if(i-1<0 ||grid[i-1][j]==0){
                    perimeter+=1;
                }
                }                
            }
        }
        return perimeter;
    }
};
