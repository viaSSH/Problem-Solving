class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size());
        if(s[0] == '0') {
            return 0;
        }
        if(s.size() == 1) return 1;
        dp[0] = 1;
        
        if(s[1] != '0') {
            if(stoi(s.substr(0,2)) > 26) {
                dp[1] = 1;
            }
            else{
                dp[1] = 2;    
            }
            
        }
        else{
            if(stoi(s.substr(0,2)) < 26) {
                dp[1] = 1;
            }
            else{
                dp[1] = 0;
            }
        }
        
        for(int i=2 ; i<s.size() ; i++) {
            cout << "ok " << stoi(s.substr(i-1, 2))  << endl;
            if(stoi(s.substr(i-1, 2)) > 10 && stoi(s.substr(i-1, 2)) <= 26 && s[i] != '0') {
                cout << "add " << endl;
                dp[i] = dp[i-1] + dp[i-2]; 
            }
            else if(stoi(s.substr(i-1, 2)) == 0) {
                cout << "double zero" << endl;
                return 0;
            }
            else if(stoi(s.substr(i-1, 2)) > 26 && s[i] == '0') {
                return 0;
            }
            else if(stoi(s.substr(i-1, 2)) <= 26 && s[i] == '0') {
                dp[i] = dp[i-2];    
                
                
            }
            
            else {
                cout << "sustain" << endl;
                dp[i] = dp[i-1];
            }
            
        }
        
        return dp[s.size()-1];
    }
};