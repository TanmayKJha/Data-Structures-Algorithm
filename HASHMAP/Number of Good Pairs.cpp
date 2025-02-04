//USING BRUTE FORCE
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0 ;
        unordered_map<int,int>mp;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto &it:mp){
            count = count+(it.second* (it.second-1))/2;
        }
        return count;
    }
};

///////////////////////////////////////////////////////////////////////////////

//USING HAshMAp FORCE
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0 ;
        unordered_map<int,int>mp;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto &it:mp){
            count = count+(it.second* (it.second-1))/2;
        }
        return count;
    }
};
