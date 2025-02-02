class Solution {
public:
    bool checkString(string s) {
        int i =0;
        int n = s.size();

        while(i<n-1){
           if(s[i] =='b'  && s[i+1]=='a'){
            return false;
           }else if(s[i] =='a'  && s[i+1]=='b'){
            i++;
           }else if(s[i] =='a'  && s[i+1]=='a' || s[i] =='b'  && s[i+1]=='b'){
            i++;
           }
        }
        return true;               
    }
};
