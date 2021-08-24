class Solution {
public:
    int majorityElement(vector<int>& nums) {
    // sorting 알고리즘

//         sort(nums.begin(), nums.end());
        
//         int frontIdx = 0;
//         int endIdx = frontIdx + (nums.size()/2);
//         if(nums.size() % 2 == 0) {
//             endIdx--;
//         }
        
//         while(endIdx < nums.size()) {
            
            
//             if(nums[frontIdx] == nums[endIdx]) {
//                 return nums[frontIdx];
//             }
//             else{
//                 frontIdx++;
//                 endIdx++;
//             }
//         }
        
//         return -1;
        
        // Boyer-Moore majority vote 알고리즘
        int cnt = 0;
        int major = 0;
        for(int num : nums) {
            if(cnt == 0) {
              major = num;  
            } 
            
            if(major == num) {
                // cout << "+" << endl;
                cnt++;  
            } 
            else {
                // cout << "-" << endl;
                cnt--;  
            } 
        }
    
    
        return major;
    }
};