class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int ans = 0;
        for(auto i : s) {
            if(i == ' '){
                if(ans != 0) {
                    break;   
                }
            }
            else {
                ans++;    
            }
            
        }
        return ans;
    }
};