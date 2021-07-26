class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> dp;
        dp.push_back(INT_MIN);
        
        for(int i=0 ; i<nums.size() ; i++) {
            if(dp.back() < nums[i]) {
                ans++;
                dp.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return ans;
    }
};