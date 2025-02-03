class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        double currWindowAverage = 0;
        double maxAverage = -DBL_MAX;

        while(j<n){
          currWindowAverage+=nums[j];
          if(j-i+1==k){
            maxAverage = max(maxAverage,currWindowAverage/k);
            currWindowAverage-=nums[i];
            i++;
          }
          j++;
        }
           return maxAverage;
    }
};
