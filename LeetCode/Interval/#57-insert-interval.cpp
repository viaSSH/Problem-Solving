class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {  
        vector<vector<int>> ans;
        int newFront = newInterval[0];
        int newBack = newInterval[1];  
        
        for(int i=0 ; i<intervals.size() ; i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if(newBack < left) {
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
            else if(right < newFront) {
                ans.push_back(intervals[i]);
                
            }
            else if(left <= newBack || newFront <= right) {
                newInterval[0] = min(left, newInterval[0]);
                newInterval[1] = max(right, newInterval[1]);
            }
        }
        
        ans.push_back(newInterval);
        
        return ans;

    }
};