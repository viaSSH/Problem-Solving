// 0 1 0 3 12

// 1 3 12 0 0

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i] == 0) {
                int swapIdx = 0;
                for(int j=i+1 ; j<nums.size() ; j++) {
                    if(nums[j] != 0) {
                        swapIdx = j;
                        break;
                    }
                }
                
                cout << "swap " << nums[i] << ", " << nums[swapIdx] << endl;
                swap(nums[i], nums[swapIdx]);
                // cout << "swap !" << endl;
                cout << "    ";
                for(int k=0 ; k<nums.size() ; k++) {
                    cout << nums[k] << " ";
                }
                cout << endl;
                
            }
        }
    }
};
