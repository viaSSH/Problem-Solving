bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
class Solution {

public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> m;
        vector<pair<int,int>> p;
        for(auto i : arr) {
            m[i]++;
        }
        for(auto i : m) {
            p.push_back({i.first, i.second});
        }
        
        sort(p.begin(), p.end(), compare);
        
        // for(auto i : p) {
        //     cout << i.first << ", " << i.second << endl;
        // }
        int idx = 0;
        while(idx < p.size()) {
            k -= p[idx].second;
            if(k < 0) {
                break;
            }
            idx++;
        }
        return p.size() - idx;
        
        
        return 0;
    }
};