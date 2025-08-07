#include <bits/stdc++.h>
using namespace std;

class segtree{
    int segSize;
    vector<long long>nums;
    vector<int>mins;

    public:
    segtree(int n){
        segSize=1;
        while (segSize<n)
        {
            segSize*=2;
        }
        nums.assign(2*segSize, 0LL);
        mins.assign(2*segSize, 1LL);
    }

    //build
    void build(vector<long long>&a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size())
                nums[x]=a[lx];
            return;
        }
        int m=(lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        nums[x]=min(nums[2*x+1],nums[2*x+2]);
        if(nums[2*x+1]==nums[2*x+2]){
            mins[x]=mins[2*x+1]+mins[2*x+2];
        }
        else if(nums[2*x+1]<nums[2*x+2]){
            mins[x]=mins[2*x+1];
        }
        else{
            mins[x]=mins[2*x+2];
        }
    }

    void build(vector<long long>&a){
        build(a, 0, 0, segSize);
    }

    void setVal(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            nums[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            setVal(i, v, 2*x+1, lx, m);
        }
        else{
            setVal(i, v, 2*x+2, m, rx);
        }
        nums[x]=min(nums[2*x+1],nums[2*x+2]);
        if(nums[2*x+1]==nums[2*x+2]){
            mins[x]=mins[2*x+1]+mins[2*x+2];
        }
        else if(nums[2*x+1]<nums[2*x+2]){
            mins[x]=mins[2*x+1];
        }
        else{
            mins[x]=mins[2*x+2];
        }
    }

    void setVal(int i, int v){
        setVal(i,v,0,0,segSize);
    }

    long long minCalc(int l, int r, int x, int lx, int rx){
        if(lx>=r || l>=rx){
            return INT64_MAX;
        }
        if(lx >=l && rx<=r){
            return nums[x];
        }
        int m=(lx+rx)/2;
        long long s1 = minCalc(l, r, 2*x+1, lx, m);
        long long s2 = minCalc(l, r, 2*x+2, m, rx);
        return min(s1,s2);
    }

    long long minCalc(int l, int r){
        return minCalc(l,r,0,0,segSize);
    }

    long long minCount(int l,int r, int x, int lx, int rx){
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx >=l && rx<=r){
            return mins[x];
        }
        int m=(lx+rx)/2;
        long long c1 = minCount(l, r, 2*x+1, lx, m);
        long long s1=minCalc(l, r, 2*x+1, lx, m);
        long long c2 = minCount(l, r, 2*x+2, m, rx);
        long long s2 = minCalc(l, r, 2*x+2, m, rx);
        if(s1==s2){
            return c1+c2;
        }
        else if(s1<s2){
            return c1;
        }
        return c2;
    }

    long long minCount(int l,int r){
        return minCount(l, r, 0, 0, segSize);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    long long n,m;
    cin>>n>>m;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    segtree st(n);
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
            cout<<st.minCalc(l,r)<<" "<<st.minCount(l,r)<<"\n";
        }
    }
    
}