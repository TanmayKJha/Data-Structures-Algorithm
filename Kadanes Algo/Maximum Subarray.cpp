class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int sum = 0;

        for(int i = 0;i<n;i++){
            sum+=nums[i];
            maxi = max(sum,maxi);
            // if the value of sum is negative == -4
            if(sum<0){
                sum = 0;
            }
            
        }
        return maxi;
        
    }
};
