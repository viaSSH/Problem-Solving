class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        sum = nums[0];
        int numMax = sum;
        for(int i=1 ; i<nums.size() ; i++) {
            if(sum + nums[i] < nums[i]) {
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
            
            if(numMax < sum) {
                numMax = sum;
            }
        }
        return numMax;
    }
};