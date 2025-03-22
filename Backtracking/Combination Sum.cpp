class Solution {
public:
    void combination(int index, vector<int>& candidates,vector<vector<int>>& ans,int target, vector<int>& temp ){

        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }


        for(int i = index; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            combination(i,candidates,ans,target-candidates[i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        combination(0,candidates,ans,target,temp);
        return ans;
        
    }
};
