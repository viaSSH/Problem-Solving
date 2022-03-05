class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        for(int i=0 ; i<arr.size() ; i++) {
            if(arr[i] <= k) k++;
        }
        return k;
    }
};

// 2 3 4 7 11
// 1 1 1 3 6

// 2 3
// 1 2
