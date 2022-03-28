class Solution {
public:
    vector<int> ans;
    void dfs(int x, int n) {
        if(x > n) {
            return;
        }
        if(x <= n) {
            ans.push_back(x);
        }
        for(int i=0 ; i<=9 ; i++) {
            dfs(x*10 + i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i=1 ; i<=9 ; i++) {
            dfs(i, n);
        }
        return ans;
    }
};

// 1 10 100 101 11 12 