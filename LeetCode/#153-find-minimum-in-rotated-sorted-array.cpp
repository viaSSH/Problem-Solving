class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo+1 < hi) {
            
            int mid = (lo+hi) / 2;
            
            if(nums[lo] > nums[mid]) {
                hi = mid;
            }
            else if(nums[mid] > nums[hi]) {
                lo = mid;
            }
            else{
                return nums[lo];
            }
        }
        
        return min(nums[lo], nums[hi]);
    }
};