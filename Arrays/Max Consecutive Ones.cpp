class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxOnes = 0;
        int i  =0;
        int n = nums.size();
        while(i<n){
            int count = 0;
            while(i<n && nums[i]==1){
                count++;
                i++;
                maxOnes = max(maxOnes,count);
            }
            i++;
        }
        return maxOnes;
    }
};
