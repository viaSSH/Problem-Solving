class Solution {
public:
    static bool myComp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int ans = 0;
        sort(intervals.begin(), intervals.end(), myComp);
        int front = intervals[0][0];
        int back = intervals[0][1];
        
        
        for(int i=1 ; i<intervals.size() ; i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            
            if(left < back) {
                ans++;
            }
            else{
                front = left;
                back = right;
            }
            
            
        }
        
        return ans;
    }
};