class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         int MaxEle = INT_MIN;
         int n = nums.size();
         vector<int>result;
        for(int i =0; i<n-k+1 ;i++){
            MaxEle = INT_MIN;
            for(int j = i; j<i+k ; j++){
                MaxEle = max(MaxEle,nums[j]);
            }
           result.push_back(MaxEle);
        }
        
        return result;
    }
};
