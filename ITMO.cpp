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
bool checker(vector<vector<int>>&adj,vll &a,ll mid){
    if(a[1]>=mid){
        return true;
    }
    for(auto adjNode:adj[1]){
        bool tmp=helper(adj,a,adjNode,mid-a[1]);
        if(!tmp){
            return false;
        }
    }
    return true;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll s=0;
    ll e=n;
    ll maxi=n;
    while(s<=e){
        ll mid=(s+e)/2;
        if(mid*(mid-1)/2>=m){
            maxi=min(maxi,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    // cout<<maxi<<endl;
    maxi=n-maxi;
    if((n/2+n%2)<=m){
        cout<<0<<" "<<maxi<<endl;
        return;
    }
    ll mini=n-2*m;
    cout<<mini<<" "<<maxi<<"\n";
}  
int main(){     
    int t=1;
    // cin>>t;
    for(int j=0;j<t;j++)
    {
        solve();
    }
    
}

