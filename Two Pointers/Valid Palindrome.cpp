class Solution {
public:
    bool isPalindrome(string s) {

        string result;

       for(auto ch : s){
         if(isalnum(ch)){
            result+=tolower(ch);
          }

      }

        int n = result.size();

        int i =0;
        int j =n-1;

        while(i<=j){
            if(result[i]!=result[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
         return true;
        
    }
};
