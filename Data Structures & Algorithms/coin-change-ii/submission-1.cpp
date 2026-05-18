class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
    int solve(int ind,int a,vector<int>& coins,vector<vector<int>> &dp){
        if(a==0) return 1;

        if(a<0 || coins.size()<=ind) return 0;

        if(dp[ind][a]!=-1){
            return dp[ind][a];
        }
        int take=solve(ind,a-coins[ind],coins,dp);
        int nottake=solve(ind+1,a,coins,dp);
        return dp[ind][a]=take+nottake;
    }
};
