class Solution {
public:

    int topDown(int n, vector<int> &dp){
        // base case
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n] =  topDown(n-1,dp) + topDown(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        
        // create dp array
        vector<int>dp(n+1,-1);
        
       int ans = topDown(n,dp);
       return ans;

        }
        
};
