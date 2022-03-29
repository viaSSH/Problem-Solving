class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int lo = 1;
        int hi = nums.size() - 1;
        int mid;
        while(lo < hi) {
            mid = (lo+hi) / 2;
            
            int cnt = 0;
            for(int i=0 ; i<nums.size() ; i++) {
                if(nums[i] <= mid) {
                    cnt++;
                }
            }
            
             if(mid < cnt) {
                    hi = mid;
                }
                else{
                    lo = mid + 1;
                }
        }
        
        return lo;
        
    }
};