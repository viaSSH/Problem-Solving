class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int w = matrix[0].size();
        int h = matrix.size();
        
        int lo = 0; 
        int hi = h-1;
        int mid;
        // search height
        while(lo < hi) {
            mid = (lo+hi) / 2;
            if(matrix[mid][0] <= target && target <= matrix[mid].back()) {
                lo = mid;
                break;
            }
            else if(matrix[mid].back() < target) {
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        int find_h = lo;
        // cout << "h " << find_h << endl;
        lo = 0;
        hi = w-1;
        // search height
        while(lo < hi) {
            mid = (lo+hi) / 2;
            if(matrix[find_h][mid] == target) {
                return true;
            }
            else if(matrix[find_h][mid] < target) {
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        if(matrix[find_h][lo] == target) {
            return true;
        }
        
        return false;
    }
};