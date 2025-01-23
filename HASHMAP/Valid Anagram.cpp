class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int> mp;

        for(auto s1 : s){
            mp[s1]++;
        }
         for(auto t1 : t){
            mp[t1]--;
        }
        for(auto m : mp){
            if((m.second)==0){
               continue;
            }else{
              return false;
            }
        }
        return true;
    }
};
