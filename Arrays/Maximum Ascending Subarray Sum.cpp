class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();
        int i =0;
        while(i<n){
            int currSum =nums[i];
            while(i<n-1 && nums[i]<nums[i+1]){
                currSum+=nums[i+1];
                i++;
           }
            maxSum = max(maxSum,currSum);         
            i++;           
        }
        return maxSum;
    }
};
