class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse = 0;
        int bit;
        
        for(int i=0 ; i<32 ; i++) {
            bit = n & 1;
            reverse = reverse | bit;
            if(i == 31) break;
            bit = 0;
            reverse <<= 1;
            n >>= 1;
        }
        
        return reverse;
    }
};