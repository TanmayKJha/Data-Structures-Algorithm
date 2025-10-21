//using trie--still left---> 22/10/25

class Solution {
public:
    string longestCommonPrefix(vector<string> strs) {

      sort(strs.begin(),strs.end());     //(N)log(N) 
      string ans = "";                                                  
      int n = strs.size();          
      string first = strs[0] ;        
      string last = strs[n-1];
      int a = first.size();                   //Final T.C == nlogn + O(M) ~ nlogn
      int b = last.size();

      for(int i = 0; i< min(a,b) ; i++){ //O(min(a,b)))
            if(first[i]!=last[i]){
                return ans;
            }else{
                ans = ans+last[i];                 
            }
      }
      return ans;

    }
};


