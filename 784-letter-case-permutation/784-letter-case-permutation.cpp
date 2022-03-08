class Solution {
public:
    vector<string> ans;
    
    void bt(string s, int idx) {
        if(idx == s.size()) {
            cout << s << endl;
            ans.push_back(s);
            return;
        }
        
        if(isalpha(s[idx]) ) {
            s[idx] = toupper(s[idx]);
            bt(s, idx+1);
            s[idx] = tolower(s[idx]);
            bt(s, idx+1);
        }
        else{
            bt(s, idx+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        bt(s, 0);
        
        return ans;
    }
};