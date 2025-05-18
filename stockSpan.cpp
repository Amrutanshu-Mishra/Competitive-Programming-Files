#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>>st;
    int n;
    StockSpanner() {
        n=0;
    }
    
    int next(int price) {
        int ans=1;
        while(st.size()>0 && st.top().first<=price){
            ans+=st.top().second;
            st.pop();
        }
        st.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */