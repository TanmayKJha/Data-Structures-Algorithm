class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int n = s.size();
        int maxLen = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            if(st.find(s[j])==st.end()){
                //if the character is not found in set, first calculate the longest non repeating substring then insert that character in the set to check whether that character will repeat in future while expanding the window
                maxLen = max(maxLen,j-i+1);
                st.insert(s[j]);
                j++;
            }else{
             //if the character is found in set,1st erase the character from the set to exclude that character from the current window, then shrink the window
             st.erase(s[i]);
             i++;
            }
        }
        return maxLen;
    }
};
