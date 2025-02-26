class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int max_sum_sofar = 0;
        int min_sum_sofar = 0;

        for(int i=0; i<nums.size(); i++){
            
            max_sum_sofar+=nums[i];
            min_sum_sofar+=nums[i];
            max_sum = max(max_sum,max_sum_sofar);
            min_sum = min(min_sum, min_sum_sofar);

            if(max_sum_sofar<0) max_sum_sofar = 0;
            if(min_sum_sofar>0) min_sum_sofar = 0;

        }
        
        return max(abs(max_sum), abs(min_sum));
        
    }
};
