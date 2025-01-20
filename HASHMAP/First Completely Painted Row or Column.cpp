class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int,int>>mp;
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                int value = mat[i][j];
                mp[value] = {i,j};
            }
        }

        vector<int>rowCount(m,0);  //[i]th -->how many cell painted in a row
        vector<int>colCount(n,0);  //[i]th -->how many cell painted in a col

        for(int i =0;i<arr.size();i++){
            int value = arr[i];
            auto [row,col] = mp[value];

            rowCount[row]++;
            colCount[col]++;

            if(rowCount[row]==n || colCount[col]==m){
                return i;
            }
        }
        return -1;
    }
};
