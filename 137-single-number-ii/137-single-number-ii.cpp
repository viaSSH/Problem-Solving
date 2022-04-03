class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long sum = 0;
        set<long long> s;
        for(auto i : nums) {
            s.insert(i);
            sum += i;
        }
        for(auto i : s) {
            sum -= (i*3);
        }
        return (sum/2)*(-1);
    }
};
