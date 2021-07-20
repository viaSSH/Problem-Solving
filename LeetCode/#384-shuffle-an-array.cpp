class Solution {
private:
    vector<int> saveNums;
public:
    
    
    
    Solution(vector<int>& nums) {
        saveNums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return saveNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> temp = saveNums;
        vector<int> shf;
        int value, idx;
        for(int i=0 ; i<saveNums.size() ; i++) {
            idx = rand() % temp.size();
            value = temp[idx];
            temp.erase(temp.begin() + idx);
            shf.push_back(value);
        }
        
        return shf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */