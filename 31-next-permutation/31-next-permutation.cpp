class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> ans;
        bool once = false;
        do{
            if(once) {
                for(int i=0; i<nums.size(); i++){
                    cout << nums[i] << " ";
                    ans.push_back(nums[i]);
                }
                break;    
            }
            once = true;
            

        }while(next_permutation(nums.begin(), nums.end()));
        if(ans.empty()) {
            sort(nums.begin(), nums.end());
        }
        else{
            nums = ans;    
        }
        
    }
};