class Solution {
public:
    int M = 1e9+7;
    int rev(int num) {
    long long reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int pairs = 0;
        for(int i=0; i<nums.size(); i++){
            int value = nums[i]-rev(nums[i]);
            if(mp.find(value)!=mp.end()){
                pairs = (pairs+ mp[value])% M;
            }
           mp[value]++;
        }
        return pairs;
    }
};
