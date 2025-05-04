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
void solve(){
    int n;
    cin>>n;
    vector<string>v;
    loop(0,n){
        string s;
        cin>>s;
        v.push_back(s);
    }
    vector<vector<int>>arr1(n,vector<int>(n,1));
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(v[i][j]==v[i][j-1]){
                arr1[i][j]=1+arr1[i][j-1];
            }
            else{
                arr1[i][j]=1;
            }
        }
    }
    vector<vector<int>>arr2(n,vector<int>(n,1));
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==v[i-1][j]){
                arr2[i][j]=1+arr2[i-1][j];
            }
            else{
                arr2[i][j]=1;
            }
        }
    }
    vector<vector<int>>arr3(n,vector<int>(n,1));
    for(int i=0;i<n;i++){
        for(int j=n-2;j>=0;j--){
            if(v[i][j]==v[i][j+1]){
                arr3[i][j]=1+arr3[i][j+1];
            }
            else{
                arr3[i][j]=1;
            }
        }
    }
    vector<vector<int>>arr4(n,vector<int>(n,1));
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<n;j++){
            if(v[i][j]==v[i+1][j]){
                arr4[i][j]=1+arr4[i+1][j];
            }
            else{
                arr4[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='.'){
                continue;
            }
            ans=max(ans,min(min(arr1[i][j],arr2[i][j]),min(arr3[i][j],arr4[i][j])));
        }
    }
    cout<<ans<<endl;
}  
int main(){     
    int t=1;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        solve();
    }

}
