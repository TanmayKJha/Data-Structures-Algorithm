//Using DP
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n,false));

        //filling all 1 length char palindrome as true in dp matrix
        int maxLen = 1;
        for(int i = 0;i<n;i++){
            dp[i][i]=true;
        }
         //filling all 2 length  palindrome as true in dp matrix
        int start = 0;
        for(int i =0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                if(maxLen<2){
                 start = i;
                 maxLen = 2;
                }              
            }
        }
       // filing all palindrome whose length is greater >=3

    for(int k =3 ; k<=n;k++){
        for(int i =0; i<=n-k;i++){
              int j = i+k-1;

            if(s[i]==s[j] && dp[i+1][j-1]==true){
                dp[i][j]=true;
                if(k>maxLen){
                   start = i;
                   maxLen = k;
                }
            }
        }
    }
    return s.substr(start,maxLen);

    }
};
