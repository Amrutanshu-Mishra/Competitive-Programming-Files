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

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vll arr(n);
    loop(0,n){
        cin>>arr[i];
    }
    // loop(0,n){
    //     cout<<arr[i]<<" ";
    // }

    int idx=-1;
    ll ts=INT64_MIN;
    loop(0,n){
        if(s[i]=='0'){
            idx=i;
            break;
        }
        // ts+=arr[i];
    }
    if(idx==-1){
        ll curr1=0;
        loop(0,n){
            curr1+=arr[i];
            ts=max(ts,curr1);
            if(curr1<0){
                curr1=0;
            }
        }
        if(ts==k){
            cout<<"Yes"<<endl;
            loop(0,n){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            return;
        }
        cout<<"No"<<endl;
        return;
    }
    ll s1=INT64_MIN;
    ll s2=INT64_MIN;
    ll curr1=0;
    for(int i=idx-1;i>=0;i--){
        if(i<0){
            break;
        }
        curr1+=arr[i];
        s1=max(s1,curr1);
    }
    curr1=0;
    for(int i=idx+1;i<n;i++){
        if(s[i]=='0'){
            break;
        }
        curr1+=arr[i];
        s2=max(s2,curr1);
    }
    if(s2==INT64_MIN){
        s2=0;
    }
    if(s1==INT64_MIN){
        s1=0;
    }
    arr[idx]=k-max(s1,max(s2,s1+s2));
    for(int i=0;i<n;i++){
        if(idx==i) continue;
        if(s[i]=='0'){
            arr[i]=-1e18;
        }
    }
    ll chker=INT64_MIN;
    curr1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==-1e18){
            chker=max(chker,curr1);
            curr1=0;
            continue;
        }
        curr1+=arr[i];
        chker=max(chker,curr1);
        if(curr1<0){
            curr1=0;
        }
    }
    
    if(chker!=k){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    loop(0,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    t=1;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}