class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> p;
        vector<int> ans;
        for(int i=0 ; i<mat.size() ; i++) {
            int temp = 0;
            for(int j=0 ; j<mat[0].size() ; j++) {
                if(mat[i][j] == 1) {
                    temp++;
                }
            }
            p.push_back({temp, i});
        }
        
        sort(p.begin(), p.end());
        for(int i=0 ; i<k ; i++) {
            ans.push_back(p[i].second);
        }
        return ans;
    }
};