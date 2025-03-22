class Solution {public:
    
    void combination(int i, int sum, int k, vector<vector<int>>& result, vector<int>& temp){
        if(k==0 && sum==0){
            result.push_back(temp);
            return;
        }
        if(sum<0 || i>9 || k<0){
            return;
        }

        for(int num = i; num<=9; num++){
            temp.push_back(num);
            combination(num+1, sum-num, k-1, result, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>>result;
        vector<int>temp;
        combination(1,n,k, result, temp);
        return result;
        
    }
};
