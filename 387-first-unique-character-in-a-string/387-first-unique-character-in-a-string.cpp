class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(auto i : s) {
            m[i]++;
        }
        set<char> list;
        char uniqC = '0';
        for(auto i : m) {
            if(i.second == 1) {
                // cout << "found one " << i.first << endl;
                uniqC = i.first;
                list.insert(i.first);
                // break;
            }
        }
        if(uniqC == '0') {
            return -1;
        }
        for(int i=0 ; i<s.size() ; i++) {
            if(list.find(s[i]) != list.end()) {
                return i;
            }
            // if(s[i] == uniqC) {
            //     return i;
            // }
        }
        return -1;
    }
};