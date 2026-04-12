class Solution {
public:
    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount) {
        int mincost=dfs(coins,amount);
        return (mincost>=1e9)? -1: mincost;
    }
    int dfs(vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        if(memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        int res=INT_MAX;

        for(int coin:coins){

            if(amount-coin>=0){
                int result=dfs(coins,amount-coin);
                if(result!=INT_MAX){
                    res=min(res,1+result);
                }
            }
        }
        memo[amount]=res;
        return res;
    }
};
