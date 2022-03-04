class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int times;
        sort(s.begin(), s.end());
        map<char, int> m;
        // a a b b b c c
        
        for(int i=0 ; i<s.size() ; i++) {
            m[s[i]]++;    
        }
        
        times = m[s[0]];
        for(auto i : m) {
            if(i.second != times) {
                return false;
            }   
        }
        return true;
    }
};