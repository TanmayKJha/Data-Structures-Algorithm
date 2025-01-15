class Solution {
public:
    string frequencySort(string s) {

        string result ="";

        unordered_map<char,int>mp;
        priority_queue<pair<int, char>, vector<pair<int, char>>, 
               function<bool(pair<int, char>, pair<int, char>)>> pq(
    [](pair<int, char> a, pair<int, char> b) {
        if (a.first == b.first) {
            return a.second > b.second; // Lexicographical order for same frequency
        }
        return a.first < b.first; // Higher frequency comes first
    }
);
        

        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
        }

        for(auto p : mp){
            pq.push({p.second,p.first});
        }

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            while(front.first--){
                 result+=front.second;
            }
           
        }
        return result;
        
    }
};
