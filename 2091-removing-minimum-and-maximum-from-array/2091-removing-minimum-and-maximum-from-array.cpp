class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxNum = -999999;
        int minNum = 999999;
        for(auto i : nums) {
            maxNum = max(maxNum, i);
            minNum = min(minNum, i);
        }
        // find max,minNum index
        int frontIdx1, frontIdx2;
        int backIdx1, backIdx2;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i] == maxNum) {
                frontIdx1 = i+1;
            }
            if(nums[i] == minNum) {
                frontIdx2 = i+1;
            }
        }
        backIdx1 = nums.size() - frontIdx2 + 1;
        backIdx2 = nums.size() - frontIdx1 + 1;
        
        // cout << frontIdx1 << ", " << frontIdx2 << endl;
        // cout << backIdx1 << ", " << backIdx2 << endl;
        int answer;
        answer = frontIdx1+frontIdx2;
        answer = min(answer, (backIdx1 + backIdx2));
        answer = min(answer, (frontIdx1 + backIdx1));
        answer = min(answer, (frontIdx2 + backIdx2));
        answer = min(answer, max(frontIdx1, frontIdx2) );
        answer = min(answer, max(backIdx1, backIdx2) );
        return answer;
    }
};

// 2 6
// 3 7

// 2 3
// 6 7