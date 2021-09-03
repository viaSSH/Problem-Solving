class Solution {
public:
    string addStrings(string num1, string num2) {
        int idx = 0;
        int carry = -1;
        string ans = "";
        while(1) {
            int a, b, sum;
            int idx_a = num1.size() - 1 - idx;
            int idx_b = num2.size() - 1 - idx;
            int flag = 0;
            if(idx_a >= 0) {
                a = (num1[idx_a]) - '0';
            }
            else{
                a = 0;
                flag++;
            }
            
            if(idx_b >= 0) {
                b = (num2[idx_b]) - '0';
            }
            else{
                b = 0;
                flag++;
            }
            if(carry == 1) {
                flag--;
            }
            // cout << "check : " << a << " , " << b  << " ";
            if(flag == 2) break;
            
            if(carry == 1) {
                sum = a+b+1;
            }
            else{
                sum = a+b;
            }
            
            if(sum >= 10) {
                carry = 1;
                ans = to_string(sum-10) + ans;
            }
            else{
                ans = to_string(sum) + ans;
                carry = 0;
            }
            
            // cout << ans << endl;
            idx++;
            
        }
        
        return ans;
    }
};