class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> result;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int>freq;

        for(auto &num :nums){
            freq[num]++;
        }

        for(auto fre:freq){
            pq.push({fre.second,fre.first});
        }
        
        while(k--){
            pair<int,int> top = pq.top();
            pq.pop();
            result.push_back(top.second);
        }

        return result;
    }
};
