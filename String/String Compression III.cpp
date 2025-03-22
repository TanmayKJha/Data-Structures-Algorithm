class Solution {
public:
    string compressedString(string word) {
        int i =0;
        int count = 0;
        int n = word.size();
        string comp ="";
        while(i<n){
            char c = word[i];
            count = 0;
            
            while(i<n && c == word[i] && count<9 ){
                count++;
                i++;
            }
            
            comp+=to_string(count) +c;
          
        }
        return comp;
    }
};
