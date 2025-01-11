class Solution {
public:
    void printPermutations(vector<int>& nums, int i, vector<vector<int>> &ans){
        //base case 
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            //recursion
            printPermutations(nums,i+1,ans);
            //backtracking ->to recreate the original input
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
         printPermutations(nums,0, ans);
         return ans;

        
    }
};
