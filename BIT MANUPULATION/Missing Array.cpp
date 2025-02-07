//USING XOR
//TC-->O(n)
//SC-->O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i = 0;i<nums.size(); i++){
            ans = i^ans;
            ans = ans^nums[i]
;        }
        return ans;
    }
};
