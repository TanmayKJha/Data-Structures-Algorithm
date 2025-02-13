//Optimize approach//TC -->O(N)//SC-->O(N)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<long long,long long>mp;
    
    long long badPairs = 0;
    int j = 0;
    while(j<n){
        long long diff = nums[j]-j;
        long long totalNumsBeforeJ =j;
        badPairs+=(totalNumsBeforeJ-mp[diff]);
        mp[diff]++;
        j++;
    }
    return badPairs;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//Brute force
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    int n = nums.size();

    int pairs = 0;

    for(int i =0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(j-i != nums[j]-nums[i]){
                pairs++;
            }
        }
    }
     return pairs;   
    }
};
