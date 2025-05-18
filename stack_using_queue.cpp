#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    int N;
    MyStack() {
        N=0;
    }
    
    void push(int x) {
        q1.push(x);
        N++;
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int tmp=q1.front();
        q1.pop();
        N--;
        queue<int>t=q1;
        q1=q2;
        q2=t;
        return tmp;
    }
    
    int top() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int tmp=q1.front();
        q2.push(tmp);
        q1.pop();
        queue<int>t=q1;
        q1=q2;
        q2=t;
        return tmp;
    }
    
    bool empty() {
        return N==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
