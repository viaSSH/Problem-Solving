class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int diff = 0;
        int min_diff = INT_MAX;
        int ans = 0;
        bool found = false;
        for(int i=0 ; i<len-2 ; i++) {
            for(int j=i+1 ; j<len-1 ; j++) {
                // cout << nums[i] << ", " << nums[j] << endl;
                int lo = j+1;
                int hi = len-1;
                int mid = (lo+hi) / 2;
                while(lo <= hi) {
                    // cout << "lo : " << lo << ", hi : " << hi << endl;
                    if(nums[i] + nums[j] + nums[mid] > target) {
                        hi = mid-1;
                    }
                    else if(nums[i] + nums[j] + nums[mid] < target) {
                        lo = mid + 1;
                    }
                    else{
                        // cout << "correct" << endl;
                        ans = nums[i] + nums[j] + nums[mid];
                        found = true;
                        break;
                    }
                    if(abs(target - (nums[i] + nums[j] + nums[mid] )) < min_diff) {
                        min_diff = abs(target - (nums[i] + nums[j] + nums[mid] ));
                        
                        ans = nums[i] + nums[j] + nums[mid];
                        // cout << "update : " << ans << endl;
                    }
                    mid = (lo+hi) / 2;
                }
                if(found) break;
            }
            if(found) break;
        }
        
        return ans;
    }
};