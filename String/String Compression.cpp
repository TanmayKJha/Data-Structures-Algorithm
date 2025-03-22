class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0 ;
        
        int n = chars.size();

        while(i<n){
            char curr_char = chars[i];
            int char_count = 0 ;
            while(i<n && curr_char ==chars[i]){
                 char_count++;
                 i++;
            }
            //assign the character  
            chars[index] = curr_char;
            index++;
            //assign the character count
            if(char_count>1){
                string len = to_string(char_count);
                for(int i = 0; i<len.size(); i++){
                    chars[index] = len[i];
                    index++;
                }
            }

        }
        return index;
        
    }
};
