
/////////////////////////////////////////////////////////SUPER BRUTE FORCE//////////////////////////////////////////////////////////////////////
class Solution {
public:
int dfs(vector<vector<int>>& grid,int i, int j,vector<vector<bool>>&visited){
   
    int m = grid.size();
    int n = grid[0].size();
    
    if(i<0||i>=m||j<0||j>=n||grid[i][j]==0||visited[i][j]){
        return 0;
    }
        
        visited[i][j]=true; 
        int count =1; 
        count += dfs(grid, i+1, j, visited);
        count += dfs(grid, i-1, j, visited);
        count += dfs(grid, i, j+1, visited);
        count += dfs(grid, i, j-1, visited);
    
    return count;
}
    int largestIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        int mxArea = 0;
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    vector<vector<bool>>visited(m,vector<bool>(n,false));
                    int area  =0;
                    for(int x =0; x<m; x++){
                        for(int y = 0; y<n; y++){
                            if(grid[x][y]==1 && !visited[x][y]){
                               
                               area = max(area,dfs(grid,x,y,visited));
                            }
                        }
                    }
                   mxArea = max(mxArea,area);
                   grid[i][j]=0;    
                }
            }
        }
        if(mxArea==0){
            return m*n;
        }
        return mxArea;
    }
};
///////////////////////////////////////////////////////////BETTER BRUTE FORCR////////////////////////////////////////////////////////////////////
class Solution {
public:
int dfs(vector<vector<int>>& grid,int i, int j,vector<vector<bool>>&visited){
   
    int m = grid.size();
    int n = grid[0].size();
    
    if(i<0||i>=m||j<0||j>=n||grid[i][j]==0||visited[i][j]){
        return 0;
    }
        
        visited[i][j]=true; 
        int count =1; 
        count += dfs(grid, i+1, j, visited);
        count += dfs(grid, i-1, j, visited);
        count += dfs(grid, i, j+1, visited);
        count += dfs(grid, i, j-1, visited);
    
    return count;
}
    int largestIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        int mxArea = 0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    mxArea = max(mxArea,dfs(grid,i,j,visited));
                }
            }
        }
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    visited = vector<vector<bool>>(m,vector<bool>(n,false));
                    int area  =dfs(grid,i,j,visited);   
                    mxArea = max(mxArea,area);
                    grid[i][j]=0;                
                }                    
            }
        }

        if(mxArea==0){
            return m*n;
        }
        return mxArea;
    }
};
//////////////////////////////////////////////////////////////////////Optimal/////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int unique_id) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        grid[i][j] = unique_id;
        visited[i][j] = true;
        int count = 1;

        count += dfs(grid, i + 1, j, visited, unique_id);
        count += dfs(grid, i - 1, j, visited, unique_id);
        count += dfs(grid, i, j + 1, visited, unique_id);
        count += dfs(grid, i, j - 1, visited, unique_id);

        return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mxArea = 0;
        int unique_id = 2;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_map<int, int> mp; // unique_id -> island size

        // First DFS pass to mark islands and store their sizes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = dfs(grid, i, j, visited, unique_id);  // FIXED: Call DFS correctly
                    mp[unique_id] = area;
                    mxArea = max(mxArea, area);  // Track max island size
                    unique_id++;
                }
            }
        }

        // Second pass: Try flipping each '0' to '1' and compute the new max island size
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueId;

                    for (auto &dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];

                        if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 1) {
                            uniqueId.insert(grid[i_][j_]);
                        }
                    }

                    int overallSize = 1;
                    for (auto &id : uniqueId) {
                        overallSize += mp[id];
                    }

                    mxArea = max(mxArea, overallSize);
                }
            }
        }

        return mxArea == 0 ? m * n : mxArea;
    }
};
