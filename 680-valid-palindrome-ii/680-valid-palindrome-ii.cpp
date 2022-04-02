class Solution {
public:
    // z d e e e e z
    // 0 1 2 3 4 5 6
    bool check(string s, int left) {
        int lo = 0;
        int hi = s.size() - 1;
        if(left < 0) return false;
        for(int i=0 ; i<s.size()/2 ; i++) {
            
            if(s.substr(lo,1) != s.substr(hi,1)) {
                return check(s.substr(lo, hi-lo), left-1) | check(s.substr(lo+1, hi-lo), left-1);
            }
            else {
                lo++;
                hi--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;
        int left = 1;
        
        return check(s, 1);
    }
};
// a b c
// a a b c a a

// a a b a c