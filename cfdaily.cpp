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
bool stressTest(vector<vll>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(j+1<arr[0].size() && arr[i][j]==arr[i][j+1]){
                cout<<i<<" "<<j<<endl;
                return false;
            }
            if(i+1<arr.size() && arr[i+1][j]==arr[i][j]){
                cout<<i<<" "<<j<<endl;
                return false;
            }
        }
    }
    return true;
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<ll,ll>>v;
    ll p1=INT64_MAX;
    ll p2=INT64_MAX;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
        p1=min(p1,x+y);
        p2=min(p2,x-y);
    }
    ll ex=1e9;
    ll res;
    cout<<"?"<<" L "<<ex<<endl;
    cin>>res;
    cout.flush();
    cout<<"?"<<" L "<<ex<<endl;
    cin>>res;
    cout.flush();
    cout<<"?"<<" D "<<ex<<endl;
    cin>>res;
    cout.flush();
    cout<<"?"<<" D "<<ex<<endl;
    cin>>res;
    cout.flush();
    ll val1=p1-res+4*ex;
    cout<<"?"<<" U "<<ex<<endl;
    cin>>res;
    cout.flush();
    cout<<"?"<<" U "<<ex<<endl;
    cin>>res;
    cout.flush();
    cout<<"?"<<" U "<<ex<<endl;
    cin>>res;
    cout.flush();
    cout<<"?"<<" U "<<ex<<endl;
    cin>>res;
    cout.flush();
    ll val2=p2-res+4*ex;
    cout<<"! "<<(val1+val2)/2<<" "<<(val1-val2)/2<<endl;
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