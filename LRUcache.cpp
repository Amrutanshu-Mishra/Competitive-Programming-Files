#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    set<pair<int,int>>st;
    unordered_map<int,int>m1;
    unordered_map<int,int>cap;
    int N;
    int curr;
    int g;
    LRUCache(int capacity) {
        N=capacity;
        curr=0;
        g=1;
    }
    
    int get(int key) {
        // if(key==1){
        //     cout<<m1[key]<<endl;
        // }
        if(m1.find(key)==m1.end()){
            return -1;
        }
        st.erase({cap[key],key});
        st.insert({g,key});
        cap[key]=g;
        g++;

        return m1[key];
    }
    
    void put(int key, int value) {
        if(m1.find(key)!=m1.end()){
            m1[key]=value;
            st.erase({cap[key],key});
            st.insert({g,key});
            cap[key]=g;
            g++;
            return;
        }
        if(curr==N){
            pair<int,int>p=*st.begin();
            // cout<<"curr==N"<<" "<<key<<" "<<value<<" "<<p.second<<endl;
            st.erase(p);
            m1.erase(p.second);
            cap.erase(p.second);
            curr--;
        }
        m1[key]=value;
        st.insert({g,key});
        cap[key]=g;
        g++;
        curr++;
        // cout<<"Her"<<" "<<key<<" "<<value<<endl;
        // cout<<"cap "<<curr<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */