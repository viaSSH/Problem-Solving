class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end(), greater<int>());
        
        int left = 0;
        int right = people.size() - 1;
        // int sum = 0;
        while(left <= right) {
            ans++;
            
            if(people[left] + people[right] <= limit) {
                right--;
            }
            left++;
        }
        
        return ans;
    }
};