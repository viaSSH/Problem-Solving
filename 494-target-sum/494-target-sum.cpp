class Solution {
public:
    map<pair<int,int>,int> memo;

    int dp(vector<int> nums, int target, int idx, int sum) {
        auto find = memo.find({idx, sum});
        if(find != memo.end()) {
            return find->second;
        }
        
        if(idx < 0 && sum == target)    {
            return 1;
        }
        if(idx < 0) {
            return 0;
        }
        
        int add = dp(nums, target, idx-1, sum + nums[idx]);
        int minus = dp(nums, target, idx-1, sum - nums[idx]);
        
    

        memo[{idx, sum}] = add + minus;
        return memo[{idx, sum}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int idx = nums.size()-1;
        
        return dp(nums, target, idx, 0);
    }
};
