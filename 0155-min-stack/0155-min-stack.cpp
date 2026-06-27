class MinStack {
public:
    stack<long long>st;
    long long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        long long v=val;
        if(st.empty()){
            st.push(v);
            mini=v;
        }
        else if(v>mini) st.push(v);
        else{
            st.push(2LL*v-mini);
            mini=v;
        }
    }
    
    void pop() {
        long long top=st.top();
        st.pop();
        if(top<mini) mini=2LL*mini-top;
    }
    
    int top() {
        long long t=st.top();
        if(t<mini) return mini;
        return t;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */