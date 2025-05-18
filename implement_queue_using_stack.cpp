#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    // int top;
    MyQueue() {

    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int ele=st2.top();
            st2.pop();
            return ele;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int ele=st2.top();
        st2.pop();
        return ele;
    }
    
    int peek() {
        if(!st2.empty()){
            int ele=st2.top();

            return ele;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int ele=st2.top();
        return ele;
    }
    
    bool empty() {
        if(st1.empty()&&st2.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */