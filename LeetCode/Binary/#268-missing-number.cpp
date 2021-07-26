class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int max = 0;
        bool isZero = false;
        // if(nums.size() == 1) return 1;
        
        for(int i=0 ; i<nums.size() ; i++) {
            sum += nums[i];
            if(max < nums[i]) max = nums[i];
            
            if(nums[i] == 0) isZero = true;
        }
        int diff = 0;
        
        diff = ((max+1) * max / 2) - sum;
        
        if(diff == 0 && isZero) {
            return max+1;
        }
        return diff;
    }
};