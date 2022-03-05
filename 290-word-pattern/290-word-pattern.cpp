class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, string> m;
        
        vector<string> list;
        string temp = "";
        for(int i=0 ; i<s.size() ; i++) {
            if(s.substr(i,1) == " ") {
                list.push_back(temp);
                temp = "";
            }
            else{
                temp += s.substr(i,1);
            }
        }
        list.push_back(temp);
        
        if(list.size() != pattern.size()) {
            return false;
        }
        
        set<string> sets;
        
        for(auto i : list) {
            sets.insert(i);
        }
        
        for(int i=0 ; i<pattern.size() ; i++) {
           
            // cout << m[pattern.substr(i,1)] << endl;
            if(m[pattern.substr(i,1)] != "") {
                if(m[pattern.substr(i,1)] != list[i]) {
                    return false;
                }
            }
            else{
                if(sets.find(list[i]) != sets.end()) {
                    m[pattern.substr(i,1)] = list[i];        
                    sets.erase(list[i]);
                }
                else{
                    return false;
                }
                
            }
            
            
        }
        return true;
    }
};