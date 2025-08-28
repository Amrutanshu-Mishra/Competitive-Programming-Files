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

void dfs(vll &arr, int i, vector<bool>&vis, vll &tmp){
    if(vis[i]){
        return;
    }
    if(arr[i]==i){
        vis[i]=true;
        tmp.push_back(i);
        return;
    }
    vis[i]=true;
    tmp.push_back(i);
    dfs(arr,arr[i],vis,tmp);
}

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vll arr(n);
    vll ans;
    ans.push_back(-1);
    loop(0,n){
        cin>>arr[i];
    }
    vll v=arr;
    sort(v.begin(),v.end());
    int idx=n-m*k;
    // int i=0;
    int j=0;
    int count=0;
    int left=k;
    while (j<arr.size())
    {
        int l=lower_bound(v.begin()+idx,v.end(),arr[j])-v.begin();
        if(v[l]>v[idx]){
            j++;
            count++;
            // continue;
        }
        else if(v[l]==arr[j] && v[l]==v[idx]){
            j++;
            count++;
            idx++;
        }
        else{
            j++;
            // count++;
        }
        if(count==m || n-j==m*(left-1)){
            ans.push_back(j-1);
            count=0;
            left--;
        }
        if(left==1){
            break;
        }
    }
    ans.push_back(n-1);
    ll fsum=0;
    for(int i=1;i<ans.size();i++){
        int a=ans[i-1];
        int b=ans[i];
        // cout<<a<<" "<<b<<endl;
        priority_queue<ll>pq;
        for(int j=a+1;j<=b;j++){
            pq.push(arr[j]);
        }
        int curr=m;
        while(curr--){
            fsum+=pq.top();
            pq.pop();
        }
    }
    cout<<fsum<<endl;
    // for(auto i:ans){
    //     if(i==-1||i==n-1){
    //         continue;
    //     }
    //     cout<<i+1<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<k;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    t=1;
    // cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}