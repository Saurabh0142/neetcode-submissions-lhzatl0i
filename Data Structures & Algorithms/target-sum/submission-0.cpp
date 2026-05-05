class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,0,0,target);
        
    }
    int dfs(vector<int>& nums,int i,int total, int target){
        if(i==nums.size()){
            return total==target;
        }
        return dfs(nums,i+1,total+nums[i],target)+dfs(nums,i+1,total-nums[i],target);

    }
};
