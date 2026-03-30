class MinStack {
public:
    stack<int>st;
    stack<int>minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        int val1 = st.top();
        int val2 = minSt.top();
        if(val1 == val2) {
            st.pop();
            minSt.pop();
        }
        else {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
