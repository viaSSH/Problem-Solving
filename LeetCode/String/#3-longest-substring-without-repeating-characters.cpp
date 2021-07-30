class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        set<string> ss;
        int l = 0;
        for(int r=0 ; r<s.size() ; r++) {
            while(ss.find(s.substr(r,1)) != ss.end()) {
                ss.erase(s.substr(l,1));
                l++;
            }
            ss.insert(s.substr(r,1));
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};