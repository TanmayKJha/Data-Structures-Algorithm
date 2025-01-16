class Solution {
public:

    void dfs(vector<vector<char>>& board, vector<vector<int>> &vis,
int row , int col ){
        int m = board.size();
        int n = board[0].size();
        vis[row][col]=1;

        int delrow[] ={-1,0,1,0};
        int delcol[] ={0,1,0,-1};

        for(int i =0; i<4; i++){
            int newR = row +delrow[i];
            int newC = col +delcol[i];
            if(newR>=0 && newR<m && newC >=0 && newC<n && vis[newR][newC]!=1 && board[newR][newC]=='O'){
                dfs(board,vis,newR,newC);
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));   

        //Traversing 1st row
        for(int i =0; i<n; i++){
            if(board[0][i]=='O' && vis[0][i]!=1){
                dfs(board,vis,0,i);
            }
        //Traversing last row
            if(board[m-1][i]=='O' &&vis[m-1][i]!=1){
                dfs(board,vis,m-1,i);
            }
        }
        //traversing first column
        for(int j =0; j<m; j++){
            if(board[j][0]=='O'&&vis[j][0]!=1){
                dfs(board,vis,j,0);
            }
        //traversing last column
            if(board[j][n-1]=='O'&&vis[j][n-1]!=1){
                dfs(board,vis,j,n-1);
            }
        }
       //traversing whole matrix after marking all boundary 'Os' as 1 using dfs 
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(vis[i][j]!=1 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }       
        
    }
};
