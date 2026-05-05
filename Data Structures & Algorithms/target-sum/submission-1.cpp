class Solution {
public:
    vector<vector<int>> dp;
    int totalsum;
    int findTargetSumWays(vector<int>& nums, int target) {
        totalsum=accumulate(nums.begin(),nums.end(),0);
        dp=vector<vector<int>>(nums.size(),vector<int>(2*totalsum+1,INT_MIN));
        return dfs(0,0,nums,target);
    }
    int dfs(int i,int total,vector<int>& nums, int target){
        if(i==nums.size()) return total==target;

        if(dp[i][total+totalsum]!=INT_MIN){
            return dp[i][total+totalsum];
        }
        dp[i][totalsum+total]=dfs(i+1,total+nums[i],nums,target)+
        dfs(i+1,total-nums[i],nums,target);

        return dp[i][total+totalsum];

    }
};
