class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int curMin = 99999;
        int curMax = -1;
        
        int ans = -1;
        int diff = -1;
        
        for(int i=0 ; i<prices.size() ; i++) {
           
            if(prices[i] < curMin) {
                curMin = prices[i];
                curMax = prices[i];
            }
            else if(prices[i] > curMax) {
                curMax = prices[i];
                diff = curMax - curMin;
                if(ans < diff) {
                    ans = diff;
                }
            }
            
        }
        
        if(ans < 0){
            return 0;
        }
        return ans;
    }
};