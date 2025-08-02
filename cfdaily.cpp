#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define loop(j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ll> vll;
const int M = 1000000007;

int helper1(ll x,int n,vll &p,vll &a, int curr){
    int s=curr;
    int e=n-1;
    int ans=n;
    while(s<=e){
        int mid=(s+e)/2;
        ll pre=0;
        if(curr-1>=0){
            pre=a[curr-1];
        }
        ll pst=0;
        if(mid-1>=curr){
            pst=a[mid-1];
        }
        if(x+pst-pre>p[mid]){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}   

int helper2(ll x, int n, vll &p, vll &b, int curr){
    int s=curr;
    int e=n-1;
    int ans=n;
    while(s<=e){
        int mid=(s+e)/2;
        // cout<<mid<<endl;
        ll pre=0;
        if(curr-1>=0){
            pre=b[curr-1];
        }
        ll pst=0;
        if(mid-1>=curr){
            pst=b[mid-1];
        }
        if(x-1*(pst-pre)<=p[mid]){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vll p(n),a(n),b(n);
    loop(0,n){
        cin>>p[i]>>a[i]>>b[i];
    }
    loop(1,n){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        // cout<<x<<endl;
        int curr=0;
        while (curr<n)
        {
            if(x<=p[curr]){
                int j=helper1(x,n,p,a,curr);
                // cout<<curr<<" idx1 "<<j<<endl;
                ll pre=0;
                if(curr-1>=0){
                    pre=a[curr-1];
                }
                ll pst=0;
                if(j-1>=curr){
                    pst=a[j-1];
                }
                x+=pst-pre;
                // cout<<x<<endl;
                curr=j;
            }
            else{
                int j=helper2(x,n,p,b,curr);
                // cout<<curr<<" idx2 "<<j<<endl;
                if(j==curr-1){
                    x=0;
                    curr++;
                    continue;
                }
                ll pre=0;
                if(curr-1>=0){
                    pre=b[curr-1];
                }
                ll pst=0;
                if(j-1>=curr){
                    pst=b[j-1];
                }
                
                x-=pst-pre;
                // cout<<x<<endl;
                x=max<ll>(x,0);
                // cout<<pst<<" "<<pre<<endl;
                curr=j;
            }
        }
        cout<<x<<endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}