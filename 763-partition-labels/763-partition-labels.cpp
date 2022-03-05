class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<string, pair<int,int>> m;
        // map<string, vector<int>> m;
        vector<int> ans;
        
        for(int i=0 ; i<s.size() ; i++) {
            if(m.find(s.substr(i,1)) == m.end()) {
                m[s.substr(i,1)].first = i;
            }
            else{
                m[s.substr(i,1)].second = i;
            }
        }
        vector<pair<int,int>> orders;
        for(auto i : m) {
            
            if(i.second.second == 0) {
                i.second.second = i.second.first;
            }
            // cout << i.first << " : " << i.second.first << ", " << i.second.second << endl;
            orders.push_back({i.second.first, i.second.second});
        }
        sort(orders.begin(), orders.end());
        
        for(auto i : orders) {
            // cout << "## " << i.first << " , " << i.second << endl;
        }
        
        int idx = 0;
        for(int i=0 ; i<orders.size() ; i++) {
            int start = orders[i].first;
            int end = orders[i].second;
            // cout << "i start " << i << endl;
            
            for(int j=i ; j<orders.size() ; j++) {
                int nextFront = orders[j].first;
                int nextEnd = orders[j].second;
                if(nextFront < end && nextEnd < end) {
                    
                }
                else if(nextFront < end && end < nextEnd) {
                    end = nextEnd;
                }
                else if(end < nextFront ){
                    ans.push_back(end-start+1);
                    // cout << "insert " << start << ", " << end << endl;
                    i = j-1;
                    break;
                }
                else{
                    // cout << "something error" << endl;
                }
                if(j == orders.size()-1) {
                    ans.push_back(end-start+1);
                    // cout << "@@ insert " << start << ", " << end << endl;
                    i = j+1;
                }
            }
        }
            
            
        
        
        
        return ans;
    }
};
// abadcd
// a - 0 2
// b - 1
// c - 4
// d - 3 5