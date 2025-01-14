///////////////////////////////////////////////////////BFS/////////////////////////////////////////
class Solution {
public:

    void bfs(vector<vector<char>>&grid, int i, int j, int m, int n){

        int dx[]= {-1,0,1,0};
        int dy[]= {0,1,0,-1};


        if(i<0 ||i>=m || j<0||j>=n || grid[i][j]=='0'|| grid[i][j]=='$'){
            return;
        }

        queue<pair<int,int>>que;
        que.push({i,j});

        while(!que.empty()){

            pair<int,int> front = que.front();
            que.pop();
            int row = front.first;
            int col = front.second;

            for(int i= 0;i<4;i++){
                int newRw = row + dx[i];
                int newCl = col + dy[i];

                if(newRw<0||newRw>=m || newCl<0||newCl>=n || grid[newRw][newCl]=='0'||grid[newRw][newCl]=='$'){
                    continue;
                } else{
                    que.push({newRw,newCl});
                    grid[newRw][newCl]='$';
                }
            }
        }



    }

    int numIslands(vector<vector<char>>& grid) {

        int m =grid.size();
        int n =grid[0].size();

        int NoIslands = 0;

        for(int i =0;i<m;i++){
            for(int j =0; j<n; j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j,m,n);
                    NoIslands+=1;
                }
            }
        }
        return NoIslands;
        
    }
};


/////////////////////////////////////////DFS//////////////////////////////////////////////

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j,int m , int n){
        if(i<0||i>=m || j<0||j>=n || grid[i][j]=='0'||grid[i][j]=='$'){
            return;
        }

        if(grid[i][j]=='1'){
            grid[i][j]= '$';

            dfs(grid,i,j+1,m,n); //right
            dfs(grid,i,j-1,m,n); //left
            dfs(grid,i+1,j,m,n); //top
            dfs(grid,i-1,j,m,n); //down
        }

    }
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int noIslands = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,m,n);
                    noIslands+=1;
                }

            }
        }
        return noIslands;
    }
};
