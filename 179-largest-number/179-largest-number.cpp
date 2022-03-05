bool comp(string a, string b) {
    
    return stol(a+b) > stol(b+a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> list;
        
        for(auto i : nums) {
            list.push_back(to_string(i));
        }
        sort(list.begin(), list.end(), comp);
        
        for(auto i : list) {
            // cout << i << endl;
            if(ans == "0" && i == "0") {
                
            }
            else{
                ans += i;    
            }
            
        }
        
        return ans;
    }
};
