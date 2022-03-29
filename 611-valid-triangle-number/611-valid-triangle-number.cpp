class Solution {
public:
    
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) {
          return 0;  
        } 
        int res = 0;
        sort(nums.begin(), nums.end()); 

        for(int i = 2; i<nums.size(); i++) {
            int l = 0, r = i - 1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]) {
                    res += (r - l);
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return res;
    }
};
// 2 2 3 4