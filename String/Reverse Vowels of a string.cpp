class Solution {
public:

    bool isVowel(char c){
        
        if(c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u'|| c=='A'|| c=='E'|| c=='I'|| c =='O'|| c=='U'){
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {

        int n = s.size();
        int i =0;
        int j = n-1;

        while(i<=j){
            if(!isVowel(s[i])){
                i++;
                continue;
            }

            else if(!isVowel(s[j])){
                j--;
                continue;
            }else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
           
        }

        return s;
        
    }
};
