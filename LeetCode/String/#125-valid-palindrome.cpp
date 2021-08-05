class Solution {
public:
    bool isPalindrome(string s) {
        string word = "";
        
        for(int i=0 ; i<s.size() ; i++) {
            if(isalpha(s[i]) || isdigit(s[i])) {
                word += tolower(s[i]);
            }
        }
        cout << word << endl;
        int len = word.size();
        for(int i=0 ; i< len / 2 ; i++) {
            if(word[i] != word[len-i-1]) {
                return false;
            }
        }
        
        
        return true;
    }
};