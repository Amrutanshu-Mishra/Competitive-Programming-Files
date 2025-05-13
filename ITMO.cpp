#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define loop(j,n) for(int i = j; i < n;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ll> vll;

const int M=1e9+7;
int get_bit(ll n,ll pos){
    return (n&(1LL<<pos))!=0;
}
ll set_bit(ll n,int pos){
    n=n|(1<<pos);
    return n;
}
ll clear_bit(ll n,int pos){
    int ele=1<<pos;
    ele=~ele;
    n=n&ele;
    return n;
}
void update_bit(int &n,int pos,int value){
    int mark=~(1<<pos);
    n=n&mark;
    n=n|(value<<pos);
}
ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll ele=a*b;
    ll ele1=gcd(a,b);
    return ele/ele1;
}
ll binexp(ll a,ll b,ll m){
    ll result=1;
    while(b>0){
        if(b&1){
            result=(result*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b>>=1;
    }
    return result;
}
ll modexp(ll a){
    return binexp(a,M-2,M);
}
vector<ll>seive_arr(1e7+7,1);
void seive(){
    for (int i = 2; i*i <= 1e7; i++)
    {
        if(seive_arr[i]==1){
            for (int j = i*i; j <= 1e7; j+=i)
            {
                seive_arr[j]=i;
            }
        }
    }
    
}
bool checker(vector<pair<ll,ll>>&coord,ll tc,int n){
    vector<vector<int>>adj(n);
    loop(0,n){
        for(int j=i+1;j<n;j++){
            if(coord[i].first==coord[j].first && coord[i].second==coord[j].second){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
            else if(coord[i].first==coord[j].first){
                if(tc>=(abs(coord[i].second-coord[j].second))/2+(abs(coord[i].second-coord[j].second))%2){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            else if(coord[i].second==coord[j].second){
                if(tc>=(abs(coord[i].first-coord[j].first))/2+(abs(coord[i].first-coord[j].first))%2){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            else{
                ll t1=max(abs(coord[i].first-coord[j].first),abs(coord[i].second-coord[j].second));
                if(tc>=t1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    vector<bool>vis(n,false);
    queue<int>q;
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            q.push(i);
            while (!q.empty())
            {
                int node=q.front();
                q.pop();
                vis[node]=true;
                for(auto j:adj[node]){
                    if(!vis[j]){
                        q.push(j);
                        vis[j]=true;
                    }
                }
            }
            
        }
    }
    if(count==1){
        return true;
    }
    return false;
}
void solve(){
    int n;
    cin>>n;
    vi arr(n+1);
    loop(1,n+1){
        cin>>arr[i];
    }
    set<int>st;
    vector<int>ans;
    int tmp=n;
    while (tmp--)
    {
        int d;
        cin>>d;
        int count=0;
        while(st.find(d)==st.end()){
            count++;
            st.insert(d);
            d=arr[d];
        }
        // cout<<d<<" "<<count<<" "<<arr[d]<<endl;
        ans.push_back(count);
    }
    // loop(0,n){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<n;i++){
        ans[i]+=ans[i-1];
    }
    loop(0,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}  
int main(){     
    int t=1;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        solve();
    }
    
}
