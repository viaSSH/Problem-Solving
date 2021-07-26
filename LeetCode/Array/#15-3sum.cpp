class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        if(nums.size() < 3) {
            return ans;
        }
        int first, second;
        for(int i=0 ; i<nums.size()-2 ; i++) {
            first = nums[i];
            int memoFirst = 9999999;
            int memoSecond = 9999999;
            for(int j=i+1 ; j<nums.size()-1 ; j++) {
                
                second = nums[j];
                int lo = j+1;
                int hi = nums.size()-1;
                int target = (first+second) * (-1);
                int mid;
                int found = false;
                
                if(first == memoFirst && target == memoSecond) {
                    continue;
                }
                
                
                while(lo <= hi) {
                    mid = (lo+hi) / 2;
                    if(nums[mid] == target) {
                        found = true;
                        break;
                    }
                    else if(nums[mid] < target) {
                        lo = mid+1;
                    }
                    else{
                        hi = mid-1;
                    }
                }
                if(found) {
                        memoFirst = first;
                        memoSecond = target;
                        ans.push_back({first, second, nums[mid]});    
                    // }
                    
                }
            }
        }
        
        if(ans.size() == 0) {
            return ans;
        }
        sort(ans.begin(), ans.end());
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );

        
        return ans;
    }
};