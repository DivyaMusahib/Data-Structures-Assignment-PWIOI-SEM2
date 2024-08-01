// https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/1340751170

class CustomStack {
public:
    int m;
    stack<int> st;
    CustomStack(int maxSize) {
        m = maxSize;
    }
    
    void push(int x) {
        if(st.size() == m)
            return;
        st.push(x);
    }
    
    int pop() {
        if(st.empty())
            return -1;
        int x = st.top();
        st.pop();
        return x;   
    }
    
    void increment(int k, int val) {
        vector<int> v;
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        int i=0, j=v.size()-1;
        while(i < v.size() && k) {
            v[j] += val;
            i++, j--, k--;
        }
        reverse(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            st.push(v[i]);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */