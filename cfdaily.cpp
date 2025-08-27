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
    int n;
    cin>>n;
    vll arr(n+1);
    map<int,int>idx;
    map<int,int>val;
    loop(1,n+1){
        cin>>arr[i];
        idx[arr[i]]=i;
        val[i]=arr[i];
    }
    vector<vll>v;
    vector<bool>vis(n+1,false);
    vis[0]=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vll tmp;
            dfs(arr,i,vis,tmp);
            v.push_back(tmp);
        }
    }
    ll ans=0;
    for(auto v1:v){
        ll ans1=0;
        for(int i=0;i<v1.size();i++){
            if(idx[arr[v1[i]]]==arr[v1[i]]){
                continue;
            }
            int idx1=idx[arr[v1[i]]];
            int val1=arr[v1[i]];
            int val2=val[arr[v1[i]]];
            val[arr[v1[i]]]=arr[v1[i]];
            val[idx1]=val2;
            idx[val2]=idx1;
            idx[arr[v1[i]]]=arr[v1[i]];
            ans1++;
        }   
    }
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