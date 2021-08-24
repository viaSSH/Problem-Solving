class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        
        for(int i=0 ; i<columnTitle.size() ; i++) {
            int num = columnTitle[i] - 'A' + 1;
            cout << num << endl;
            int val = num;
            int cnt = columnTitle.size() - i -1;
            
            while(cnt > 0) {
                val *= 26;
                cnt--;
            }
            ans += val;
        }
        
        return ans;
    }
};