class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits = nums[0];
        for(int i=1 ; i<nums.size() ; i++) {
            bits ^= nums[i];
        }
        return bits;
    }
    
    
};

// 10 
// 10  00
// 01  01

// 100
// 001 010
// 010 111
// 001 001
// 010 100

