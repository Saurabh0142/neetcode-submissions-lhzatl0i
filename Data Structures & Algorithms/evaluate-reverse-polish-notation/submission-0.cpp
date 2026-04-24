class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        
        stack<int> st;
        int s=0;
        for(string token : tokens){
            if(token != "+" && token != "-" && token != "*" && token != "/" ){
                st.push(stoi(token));
            }
            else{
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if(token=="+") st.push(a+b);
                if(token=="-") st.push(a-b);
                if(token=="*") st.push(a*b);
                if(token=="/") st.push(a/b);
            }
        }
        return st.top();
    }
};
