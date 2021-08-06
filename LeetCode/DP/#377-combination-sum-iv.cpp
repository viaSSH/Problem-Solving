class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target);
        dp.push_back(0);
        sort(nums.begin(), nums.end());
        
        int idx = 0;
        for(int i=1 ; i<=target ; i++) {
            long long cnt = 0;
            if(idx < nums.size() && i == nums[idx]) {
                cnt++;
                idx++;
            }
            
            for(int j=0 ; j<nums.size() ; j++) {
                if(i - nums[j] < 1) continue;
                
                cnt += dp[i - nums[j]];
            }
            dp[i] = cnt;
        }
        
        return dp[target];
    }
};