//Using two HashMAp
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> temp;
        string word;

        while (ss >> word) {  // Extract words from s
            temp.push_back(word);
        }

        if (pattern.size() != temp.size()) {
            return false;
        }

        unordered_map<string, char> wordToChar;
        unordered_map<char, string> charToWord;

        for (int i = 0; i < pattern.size(); i++) {
            string currWord = temp[i];
            char currChar = pattern[i];

            // Check if mappings exist and are inconsistent
            if (wordToChar.find(currWord) != wordToChar.end() && wordToChar[currWord] != currChar) {
                return false;
            }
            if (charToWord.find(currChar) != charToWord.end() && charToWord[currChar] != currWord) {
                return false;
            }

            // Establish mapping
            wordToChar[currWord] = currChar;
            charToWord[currChar] = currWord;
        }

        return true;
    }
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//USing HashMap and HashSet
class Solution {
public:
    bool wordPattern(string pattern, string s) {
 
        stringstream ss(s);
        vector<string>temp;
        string word;
        int count = 0;
        while(getline(ss,word,' ')){
            temp.push_back(word);
            count++;
        }
        int n = pattern.size();

        if(n!=count){
            return false;
        }
           
        unordered_map<string,char> mp;
        unordered_set<char>st;

        for(int i =0; i<n; i++){
            if(mp.find(temp[i])==mp.end() && st.find(pattern[i])==st.end()){
                mp[temp[i]]=pattern[i];
                st.insert(pattern[i]);
            }else if(mp[temp[i]]!=pattern[i]){
                return false;
            }
        }
        return true;
 
    }
};
