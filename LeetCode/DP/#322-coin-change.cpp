class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10001);
        dp[0] = 0;
        for(int i=0 ; i<coins.size() ; i++) {
            if(coins[i] > 10000) continue;
            dp[coins[i]] = 1;
        }
        
        for(int i=1 ; i<=10000 ; i++) {
            if(dp[i] > 0) continue;
            int min = INT_MAX;
            int check;
            for(int j=0 ; j<coins.size() ; j++) {
                
                if(i-coins[j] < 0) continue;
                if(dp[i-coins[j]] == -1) continue;
                check = dp[i-coins[j]] + 1;
                if(min > check) {
                    min = check;
                }
            }
            if(min != INT_MAX) {
                dp[i] = min;
            }
            else{
                dp[i] = -1;
            }
        }
        
        return dp[amount];
    }
};