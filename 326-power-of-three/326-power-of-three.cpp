class Solution {
public:
    bool check(int n) {
        if(n == 1) {
            return true;
        }
        
        if(n%3 != 0) {
            return false;
        }
        
        return check(n/3);
    }
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        return check(n);
    }
};

// 3 9 27 81 243 729
//