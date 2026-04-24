class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || minst.top()>=val){
            minst.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()==minst.top()) minst.pop();

        st.pop();
    }
    
    int top() {
        if(!st.empty()) return st.top();
    }
    
    int getMin() {
        if(!st.empty()) return minst.top();
    }
};
