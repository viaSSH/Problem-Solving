class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(1);
        ans.push_back(cur);
        if(numRows > 1) {
            cur.push_back(1);
            ans.push_back(cur);
        }
        // 1 1
        for(int i=3 ; i<=numRows ; i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j=1 ; j<i-1 ; j++) {
                temp.push_back(cur[j-1] + cur[j]);
            }
            temp.push_back(1);
            cur = temp;
            ans.push_back(cur);
        }
        
        
        return ans;
    }
};