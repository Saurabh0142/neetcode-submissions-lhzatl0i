class Solution {
public:
    vector<int> mem;
    int rob(vector<int>& nums) {
        mem.resize(nums.size(),-1);
        return solve(nums,0);
        
    }
    int solve(vector<int>&nums, int idx){
        if(idx>=nums.size()){
            return 0;
        }
        if(mem[idx]!=-1){
            return mem[idx];
        }
        mem[idx]= max(solve(nums,idx+1),nums[idx]+solve(nums,idx+2));
        return mem[idx];

    }
};
