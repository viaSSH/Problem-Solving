class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        
        for(auto i : s) {
            if(i == '#') {
                if(!s1.empty()) {
                    s1.pop();
                }
                
            }
            else{
                s1.push(i);
            }
        }
        for(auto i : t) {
            if(i == '#') {
                if(!s2.empty()) {
                    s2.pop();    
                }
                
            }
            else{
                s2.push(i);
            }
        }
         
        while(!s1.empty() && !s2.empty()) {
            char c1, c2;
            c1 = s1.top();
            s1.pop();
            c2 = s2.top();
            s2.pop();
            if(c1 != c2) {
                return false;
            }
        }
        
        if(!s1.empty() || !s2.empty()) {
            return false;
        }
        
        return true;
    }
};