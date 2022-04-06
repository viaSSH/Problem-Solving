class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long ans = 0;
        map<int, int> m;
        set<int> s;
        
        for(auto i : arr) {
            m[i]++;
            s.insert(i);
        }
        vector<int> uniq;
        
        for(auto i : s) {
            uniq.push_back(i);
        }
        sort(uniq.begin(), uniq.end());
        int len = uniq.size();
        // 1 2 3 4 5
        for(int i=0 ; i<len ; i++) {
            for(int j=i ; j<len ; j++) {
                for(int k=j ; k<len ; k++) {
                    int threeSum = uniq[i] + uniq[j] + uniq [k];
                    if(threeSum == target) {
                        // cout << "check three " << uniq[i] << ", " << uniq[j] << ", " << uniq[k] << endl;
                        long long ii = m[uniq[i]];
                        long long jj = m[uniq[j]]; if(i == j) jj--;
                        long long kk = m[uniq[k]]; if(j == k) kk--; if(i == k) kk--;
                        long long mul = ii * jj * kk;
                        if(i == j && i == k) mul /= 6;
                        else if(i == j || j == k) mul /= 2;
                        // cout << mul << endl;
                        ans += mul;
                        ans %= (1000000000+7);
                    }
                    else if(threeSum < target) {
                        
                    }
                    else{
                        break;
                    }
                }
            }
        }
        
        return ans % (1000000000+7);
    }
};

// 1 2 3 4 5