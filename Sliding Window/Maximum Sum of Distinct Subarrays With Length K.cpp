class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_set<int>st;
        long long currWinSum = 0;
        long long result = 0;

        int i  = 0;
        int j =0;

        while(j<nums.size()){

            while(st.count(nums[j])){
                currWinSum-=nums[i];
                st.erase(nums[i]);
                i++;
           }

            currWinSum+=nums[j];
            st.insert(nums[j]);

            if(j-i+1==k){
                result = max(currWinSum,result);
                currWinSum-=nums[i];
                st.erase(nums[i]);
                i++;

            }

            j++;

        }
        return result;
        
    }
};
