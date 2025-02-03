class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1;
        int n = nums.size();
        int i= 0;
        while(i<n-1){
            int len = 1;
            while( i<n-1 && nums[i]<nums[i+1] ){
                len++; 
                i++;   
                maxLen = max(maxLen,len);       
            }
            len =1;
            while( i<n-1  && nums[i]>nums[i+1] ){
                len++;
                i++;
                maxLen = max(maxLen,len);
            }
            if(i<n-1  && nums[i]==nums[i+1]){
                i++;
            }
        }
       return maxLen;        
    }
};
