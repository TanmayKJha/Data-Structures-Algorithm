//USING SORTING

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result ="";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        for (int i=0; i<min(first.size(), last.size()); i++){
            if(first[i]!=last[i]){
                return result;
            }
            else{
                result = result+first[i];
            }
        }
        return result;
    }
};


//USING TRIE

