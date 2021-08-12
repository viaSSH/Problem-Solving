class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return nums[0];
        }
        else if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        else if(nums.size() == 3) {
            return max({nums[0], nums[1], nums[2]});
        }
        // make two cases
        // first, include first, except last
        vector<int> dp1(nums.size()-1);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        
        for(int i=2 ; i<nums.size() - 1 ; i++) {
            dp1[i] = max(dp1[i-2]+nums[i] , dp1[i-1]);
        }
        // second case
        vector<int> dp2(nums.size()-1);
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for(int i=2 ; i<nums.size()-1 ; i++) {
            dp2[i] = max(dp2[i-2]+nums[i+1] , dp2[i-1]);
        }
        
        
        return max(dp1[nums.size()-2], dp2[nums.size()-2]);
        
    }
};