class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> n3; //(m+n, 0);
        int idx1 = 0;
        int idx2 = 0;
        while(idx1 < m && idx2 < n) {
            if(nums1[idx1] < nums2[idx2]) {
                n3.push_back(nums1[idx1]);
                idx1++;
            }
            else{
                n3.push_back(nums2[idx2]);
                idx2++;
            }
        }
        
        for(int i=idx1 ; i<m ; i++) {
            n3.push_back(nums1[i]);
        }
        for(int i=idx2 ; i<n ; i++) {
            n3.push_back(nums2[i]);
        }
        
        for(int i=0 ; i<m+n ; i++) {
            nums1[i] = n3[i];
        }
    }
};
// 1 2 3 0 0 0
// 2 5 6

// 1 2 2 3 0 0
//   5 6

// 2 0
// 1