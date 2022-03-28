class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(100001, 0);
        int reach = 0;
        if(nums.size() == 1) return true;
        for(int i=0 ; i<nums.size() ; i++) {
            
            reach = max(reach, nums[i]+i);
            
            if(reach == i) {
                return false;
            }
            
            if(reach >= nums.size()-1) {
                return true;
            }
        }
        
        return false;
    }
};
// 0 1 1 0 0
//     2 1 1

// 1 1 1 0 0
//     1 1