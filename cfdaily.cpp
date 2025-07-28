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

void solve()
{
    int n;
    cin>>n;
    vll arr(n);
    loop(0,n){
        cin>>arr[i];
    }
    vll diff;
    for(int i=1;i<n;i++){
        diff.push_back(abs(arr[i]-arr[i-1]));
    }
    for(int i=1;i<diff.size();i+=2){
        diff[i]=-1*diff[i];
    }
    long long ans=INT64_MIN;
    long long curr=0;
    for(int i=0;i<diff.size();i++){
        curr+=diff[i];
        ans=max(ans,curr);
        if(curr<0){
            curr=0;
        }
    }
    for(int i=0;i<diff.size();i++){
        diff[i]=-1*diff[i];
    }
    curr=0;
    for(int i=0;i<diff.size();i++){
        curr+=diff[i];
        ans=max(ans,curr);
        if(curr<0){
            curr=0;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}