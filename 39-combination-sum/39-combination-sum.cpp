class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> cur;
    
    void bt(vector<int> candidates, int sum, int idx, int target) {
        if(sum > target) {
            return;
        }
        else if(sum == target) {
            ans.push_back(cur);
        }
        
        for(int i=idx ; i<candidates.size() ; i++) {
            cur.push_back(candidates[i]);
            sum += candidates[i];

            bt(candidates, sum, i, target);

            sum -= candidates[i];
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int sum = 0;
        bt(candidates, sum, 0, target);
        
        return ans;
        
    }
};