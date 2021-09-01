class Solution {
public:
    int max;
    vector<string> ans;
    void go(int open, int close, string cur) {
        
        if(cur.size() == max*2) {
            ans.push_back(cur);
            return;
        }
        
        if(open < max) {
            go(open+1, close, cur+"(");
        }
        if(close < open) {
            go(open, close+1, cur+")");
        }
            
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        
        string cur = "";
        max = n;
        go(open, close, cur);
        
        return ans;
    }
};

        
    
    
    

    