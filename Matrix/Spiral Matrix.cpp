class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int top =0;
        int left = 0;
        int down =m-1;
        int right = n-1;
        //dir
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top
        if(matrix.size() == 0)
            return {};

        int dir =0;
        while(top<=down && left<=right){
        if(dir ==0){
            for(int i = left ; i<=right;i++){
            result.push_back(matrix[top][i]);
            }
            top++;

        }
        if(dir ==1){
            for(int i = top ; i<=down;i++){
            result.push_back(matrix[i][right]);
            }
            right--;

        }
        if(dir ==2){
            for(int i =right ; i>=left;i--){
                result.push_back(matrix[down][i]);
            }
            down--;

        }
        if(dir ==3){
            for(int i = down ; i>=top;i--){
                result.push_back(matrix[i][left]);
            }
            left++;

        }
        
        dir = (dir+1)%4;

        }
        return result;
    }
};
