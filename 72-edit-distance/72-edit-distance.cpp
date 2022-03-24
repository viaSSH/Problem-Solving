class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        
        return check(word1, word2, m, n, memo);
    }
    
    int check(string w1, string w2, int m, int n, vector<vector<int>> & memo) {
        if(m == 0) return memo[m][n] = n;
        if(n == 0) return memo[m][n] = m;
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if(w1[m-1] == w2[n-1]) 
            return memo[m][n] = check(w1, w2, m-1, n-1, memo);
        
        else {
            int inrt = check(w1, w2, m, n-1, memo);
            int del = check(w1, w2, m-1, n, memo);
            int rep = check(w1, w2, m-1, n-1, memo);
            
            return memo[m][n] = 1 + min({inrt, del, rep});

        }   
        
        
        
        
    }
};

// intention
// execution