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

const int M=998244353;
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

bool helper(vector<vector<int>>&adj,vll &a,int node,ll mid){
    if(adj[node].size()==0){
        if(a[node]>=mid){
            return true;
        }
        return false;
    }
    if(mid>=1e17){
        return false;
    }
    if(a[node]>=mid){
        for(auto adjNode:adj[node]){
            bool tmp=helper(adj,a,adjNode,mid);
            if(!tmp){
                return false;
            }
        }
        return true;
    }
    for(auto adjNode:adj[node]){

        bool tmp=helper(adj,a,adjNode,mid+(mid-a[node]));
        if(!tmp){
            return false;
        }
    }
    return true;
}
bool checker(vll &arr,ll n,ll mid,ll x,ll y){
    vector<int>v1;
    for(int i=0;i<=mid;i++){
        v1.push_back(arr[i]);
    }
    sort(v1.rbegin(),v1.rend());
    vector<bool>dp(x+1,false);
    dp[x]=true;
    for(auto i:v1){
        for(int j=0;j<=x;j++){
            if(dp[j]){
                dp[j%i]=true;
            }
        }
        if(dp[y]){
            return true;
        }
    }
    return dp[y];
}
void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    vll arr(n);
    loop(0,n){
        cin>>arr[i];
    }
    int j=-1;
    loop(0,n){
        if(arr[i]<=y){
            j=i;
            break;
        }
        // j=i;
    }
    if(j==-1){
        j=n;
    }
    if(j==0){
        cout<<0<<endl;
        cout<<endl;
        return;
    }
    int s=0;
    int e=j-1;
    int ans=j;
    while (s<=e)
    {
        int mid=(s+e)/2;
        if(checker(arr,n,mid,x,y)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    vector<int>v;
    loop(ans,j){
        v.push_back(i+1);
    }
    cout<<v.size()<<endl;
    for(auto i:v){
        cout<<i<<" ";
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

