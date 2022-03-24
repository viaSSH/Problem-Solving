class Solution {
public:
    string addBinary(string a, string b) {
        int x = a.size()-1;
        int y = b.size()-1;
        bool carry = false;
        string ans = "";
        while(x >= 0 && y >= 0) {
            if(a.substr(x,1) == "1" && b.substr(y,1) == "1") {
                if(carry) {
                    ans = "1" + ans;
                }
                else{
                    ans = "0" + ans;
                }
                carry = true;
            }
            else if(a.substr(x,1) == "1" || b.substr(y,1) == "1") {
                if(carry) {
                    ans = "0" + ans;
                    carry = true;
                }
                else{
                    ans = "1" + ans;
                }
            }
            else{
                if(carry) {
                    ans = "1" + ans;
                    carry = false;
                }
                else{
                    ans = "0" + ans;
                }
            }
            x--;
            y--;
        }
        
        
        while(x >= 0) {
            if(a.substr(x,1) == "1" && carry) {
                ans = "0" + ans;
                carry = true;
            }
            else if(a.substr(x,1) == "0" && carry) {
                ans = "1" + ans;
                carry = false;
            }
            else{
                ans = a.substr(x,1) + ans;
            }
            x--;
        }
        
        while(y >= 0) {
                if(b.substr(y,1) == "1" && carry) {
                    ans = "0" + ans;
                    carry = true;
                }
                else if(b.substr(y,1) == "0" && carry) {
                    ans = "1" + ans;
                    carry = false;
                }
                else{
                    ans = b.substr(y,1) + ans;
                }
                y--;
            }
        
        if(carry) {
            ans = "1" + ans;
        }
        
        return ans;
    }
};

// 11
// 11
//110