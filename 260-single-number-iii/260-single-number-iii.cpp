class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        set<int> s;
        for(auto i : nums) {
            if(s.find(i) != s.end()) {
                s.erase(i);
            }
            else{
                s.insert(i);    
            }
        }
        
        for(auto i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};

// 1 2 3 4 1 2 3 5