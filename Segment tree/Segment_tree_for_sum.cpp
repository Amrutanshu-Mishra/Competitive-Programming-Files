#include <bits/stdc++.h>
using namespace std;

class segtree{
    int segSize;
    vector<long long>sums;
    public:
    segtree(int n){
        segSize=1;
        while (segSize<n)
        {
            segSize*=2;
        }
        sums.assign(2*segSize, 0LL);
    }


    //using build is more optimised then using setVal for the initialization
    void build(vector<int>&a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        
        int m=(lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }



    void build(vector<int>&a){
        build(a, 0, 0, segSize);
    }

    void setVal(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            setVal(i, v, 2*x+1, lx, m);
        }
        else{
            setVal(i, v, 2*x+2, m, rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }

    void setVal(int i, int v){
        setVal(i,v,0,0,segSize);
    }

    long long sum(int l, int r, int x, int lx, int rx){
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx >=l && rx<=r){
            return sums[x];
        }
        int m=(lx+rx)/2;
        long long s1 = sum(l, r, 2*x+1, lx, m);
        long long s2 = sum(l, r, 2*x+2, m, rx);
        return s1+s2;
    }

    long long sum(int l, int r){
        return sum(l,r,0,0,segSize);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    segtree st(n);
    vector<int>a(n);


    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    st.build(a);

    while (m--)
    {
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.setVal(i,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<st.sum(l,r)<<"\n";
        }
    }
    
}