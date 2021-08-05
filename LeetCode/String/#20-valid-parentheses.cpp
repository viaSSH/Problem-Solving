class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        
        for(int i=0 ; i<s.size() ; i++) {
            string cut = s.substr(i,1);
            int top;
            if(cut == "(") {
                st.push(1);
            }
            else if(cut == "[") {
                st.push(2);
            }
            else if(cut == "{") {
                st.push(3);
            }
            else{
                if(st.empty()) return false;
                
                if(cut == ")") {
                    top = st.top();
                    if(top != 1){
                        return false;
                    }
                    st.pop();
                }
                else if(cut == "]") {
                    top = st.top();
                    if(top != 2){
                        return false;
                    }
                    st.pop();
                }
                else if(cut == "}") {
                    top = st.top();
                    if(top != 3){
                        return false;
                    }
                    st.pop();
                }
            } 
        }
        
        if(!st.empty()) return false;
        
        return true;
    }
};