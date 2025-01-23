
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//SORTING & HASHMAP
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        unordered_map<string,vector<string>>mp; //O(N) N equals to no of unique words or strings
        vector<vector<string>>ans;

        for(int i =0; i<n; i++){ //O(N)
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]); //O(klogk)
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
//Time complexity = N*(klogk)--> k equals to the maximum size of the word
//Space Complexity = O(N)
