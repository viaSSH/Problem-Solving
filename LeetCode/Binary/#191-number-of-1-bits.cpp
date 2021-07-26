class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0) {
            // cout << n << endl;
            if(n & 1 == 1) {
                cnt++;
            }
            n = n >> 1;
        }
        
        return cnt;
    }
};