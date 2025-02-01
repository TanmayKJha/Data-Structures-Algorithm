//In place modification--2 pass solution
//Time complexity = O(mxn)
//Space complexity = O(1)
class Solution {
public:
    int countLiveNeigbours(vector<vector<int>>& board,int i , int j,int m , int n){
        int rowChange[8]=  {-1, -1, -1, 0, 0, 1, 1, 1};
        int colChange[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
        int count = 0;
        for(int dir = 0; dir<8 ; dir++){
            int newRow = i + rowChange[dir];
            int newCol = j + colChange[dir];

            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n){
                if(board[newRow][newCol]==1 || board[newRow][newCol]==-1 ){
                    count++;
                }
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();
        
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                int liveneighbors = countLiveNeigbours(board,i,j,m,n);
                if(board[i][j]==1 && (liveneighbors<2||liveneighbors>3)){
                    board[i][j]=-1;
                }
                if(board[i][j]==0 && liveneighbors==3){
                    board[i][j]=2;
                }
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0;j<n; j++){
                if(board[i][j]==-1){
                    board[i][j]=0;
                }
                if(board[i][j]==2){
                    board[i][j]=1;
                }
            }
        }
        
    }
};
