class MinStack {
private:
    stack<pair<int,int>> st;
    int current_min; 
public:
    MinStack() {
        current_min = INT_MAX;
    }
    
    void push(int val) {
        if(!st.empty()) current_min = min(val, st.top().second);
        else current_min = val;
        st.push({val, current_min});
    }
    
    void pop() {
         st.pop();
         if(st.empty()) current_min =INT_MAX;
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
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