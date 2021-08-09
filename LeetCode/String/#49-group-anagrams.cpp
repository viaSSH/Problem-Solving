class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        map<string, vector<string>> m;
        
        for(string s: strs) {
            string k = s;
            sort(k.begin() , k.end());
            
            m[k].push_back(s);
        }
        
        for(auto i : m) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};