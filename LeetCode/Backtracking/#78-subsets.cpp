class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int> nums, int idx, vector<int> cur) {
        if(idx >= nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        solve(nums, idx+1, cur);
        cur.push_back(nums[idx]);
        solve(nums, idx+1, cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
     
        
        vector<int> cur;
        
        solve(nums, 0,  cur);
        
        return ans;
    }
};