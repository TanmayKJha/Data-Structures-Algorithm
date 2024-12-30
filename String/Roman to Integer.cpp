class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>map1{
            {'I',1},
            {'X',10},
            {'V',5},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        
        };
            
         int temp =0;

         for(int i=0; i<s.size();i++)
             {
            if(i<s.size()-1 && map1[s[i]]<map1[s[i+1]]){
                temp-=map1[s[i]];
            }else{
                temp+=map1[s[i]];
            }
        }

        return temp;
    }
};
