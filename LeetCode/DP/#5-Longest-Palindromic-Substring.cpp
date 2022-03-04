class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<char>> dp(len, vector<char>(len,0));
        int left = 0; int right = 0;
        for(int i=0 ; i<len ; i++) {
            for(int j=0 ; j<i ; j++) {
                if(s[i] == s[j] && (i-j <= 2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                }
                else{
                    dp[j][i] = false;
                }
                
                if(dp[j][i]) {
                    if(i-j > right - left) {
                        left = j;
                        right = i;
                    }
                }
            }
        }
        
        return s.substr(left, right-left+1);
        
    }
};