class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        unordered_set<int>st;
        for(int i =0; i<arr.size(); i++){
            freq[arr[i]]++;
        }

        for(auto &mp: freq){
            if(st.count(mp.second)){
                return false;
            }else{
            st.insert(mp.second);
            }           
        }
        return true;
    }
};
