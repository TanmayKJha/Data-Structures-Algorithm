//MATHEMATICAL APPROACH
//TC-->O(N);
//SC-->O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalsum = n*(n+1)/2;

        int missing  =-1;
        int actualsum = 0;

        for(int i =0; i<n;i++){
            actualsum+=nums[i];
        }
        missing = totalsum-actualsum;
        return missing;
    }
};
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
//USING HASH MAP
//TC --> O(N) + O(N)
//SC--->O(N)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int>mp; //O(n)
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        int missing = -1;
        for(int i = 0; i<=n; i++){
           if(mp[i]==0){
            missing = i;
           }
        }
        return missing;
    }
};
