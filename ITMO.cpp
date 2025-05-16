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
bool helper(int n,vi arr){
    int tmp=arr[0];
    sort(arr.begin(),arr.end());
    int idx=lower_bound(arr.begin(),arr.end(),tmp)-arr.begin();
    int count=0;
    // cout<<idx<<" ";
    if(n%2){
        if(idx==(n/2)){
            return true;

        }
        int l=idx;
        int r=n-idx-1;
        if(l<r){
            int req=n/2-l;
            
            if(arr[idx]>=0){
                for(int i=idx+1;i<n;i++){
                    if(arr[i]>0){
                        count++;
                    }
                }
            }
            else{
                for(int i=idx+1;i<n;i++){
                    if(arr[i]>abs(arr[idx])){
                        count++;
                    }
                }
            }
            if(count>=req){
                return true;
            }  
        }
        else{
            int req=n/2-r;
            
            if(arr[idx]>=0){
                for(int i=0;i<idx;i++){
                    if(abs(arr[i])>arr[idx]){
                        count++;
                    }
                }
                
            }
            else{
                for(int i=0;i<idx;i++){
                    if(arr[i]<0){
                        count++;
                    }
                }
            }
            if(count>=req){
                return true;
            }  
        }
    }
    else{
        if(idx==n/2-1){
            return true;

        }
        int l=idx;
        int r=n-idx-1;
        if(r>n/2){
            int req=n/2-l-1;
            
            if(arr[idx]>=0){
                for(int i=idx+1;i<n;i++){
                    if(arr[i]>0){
                        count++;
                    }
                }
            }
            else{
                for(int i=idx+1;i<n;i++){
                    if(arr[i]>abs(arr[idx])){
                        count++;
                    }
                }
            }
            if(count>=req){
                return true;

            }  
        }
        else{
            int req=n/2-r;
            
            if(arr[idx]>=0){
                for(int i=0;i<idx;i++){
                    if(abs(arr[i])>arr[idx]){
                        count++;
                    }
                }
                
            }
            else{
                for(int i=0;i<idx;i++){
                    if(arr[i]<0){
                        count++;
                    }
                }
            }
            if(count>=req){
                return true;

            }  
        }
    }
    // cout<<count<<endl;
    return false;
}
void solve(){
    int n;
    cin>>n;
    vvi arr(n,vi(n,0));
    int tmp=n*n-1;
    int row_max=n-1;
    int row_min=0;
    int col_min=0;
    int col_max=n-1;
    while(row_min<=row_max && col_min<=col_max){
        arr[row_min][col_min]=tmp;
        tmp--;
        arr[row_min][col_max]=tmp;
        tmp--;
        arr[row_max][col_min]=tmp;
        tmp--;
        arr[row_min][col_min]=tmp;
        tmp--;
        int a=col_min+1;
        int b=col_max-1;
        int c=row_min+1;
        int d=row_max-1;

    }
}  
int main(){     
    int t=1;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        solve();
    }
    
}

