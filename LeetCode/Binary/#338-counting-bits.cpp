// all search
class Solution {
public:
    vector<int> countBits(int n) {
        int cnt = 0;
        vector<int> ans;
        for(int i=0 ; i<=n ; i++) {
            int x = i;
            while(x > 0) {
                if(x & 1) cnt++;
                x >>= 1;
            }
            ans.push_back(cnt);
            cnt = 0;
        }
        
        return ans;
    }
};

// DP Solution
// class 