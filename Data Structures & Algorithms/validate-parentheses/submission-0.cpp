class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            char ch=s[i];

            if(s[i]=='('|| s[i]=='[' || s[i]=='{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                if((st.top() == '(' && ch == ')') ||
                   (st.top() == '[' && ch == ']') ||
                   (st.top() == '{' && ch == '}')) {
                    st.pop();
                } 
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
