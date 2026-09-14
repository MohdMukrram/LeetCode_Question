class CustomStack {
public:
    vector<int> stack;
    vector<int> inc;
    int top;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        inc.resize(maxSize, 0);
        top = -1;
    }
    
    void push(int x) {
        if(top == stack.size() - 1) return;

        stack[++top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;

        int ans = stack[top] + inc[top];

        if(top > 0) inc[top - 1] += inc[top];

        inc[top] = 0;
        top--;

        return ans;
    }
    
    void increment(int k, int val) {
        if(top == -1) return;

        int idx = min(k - 1, top);
        inc[idx] += val;
    }
};