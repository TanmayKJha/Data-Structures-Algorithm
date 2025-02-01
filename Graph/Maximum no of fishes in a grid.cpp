//DFS
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i , int j , int m , int n, vector<vector<bool>>&visited){
         if(i<0||i>=m||j<0||j>=n||grid[i][j]==0||visited[i][j]){
            return 0;
        }
        visited[i][j]= true;
        int count =grid[i][j];
        count+=dfs(grid,i+1,j,m,n,visited);
        count+=dfs(grid,i-1,j,m,n,visited);
        count+=dfs(grid,i,j+1,m,n,visited);
        count+=dfs(grid,i,j-1,m,n,visited);
        return count;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int maxFish  = 0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i =0; i<m; i++){
            for(int j =0;j<n; j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    int fish  = dfs(grid,i,j,m,n,visited);
                    maxFish = max(maxFish,fish);
                }
            }
        }
        return maxFish==0?0:maxFish;
    }
};
