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
    int n,q,c;
    cin>>n>>q>>c;
    vector<vector<vector<int>>>v(c+1,vector<vector<int>>(101,vector<int>(101,0)));
    loop(0,n){
        int x,y,s;
        cin>>x>>y>>s;
        v[s][x][y]++;
    }
    for(int k=0;k<=c;k++){
        for(int i=0;i<101;i++){
            for(int j=1;j<101;j++){
                v[k][i][j]+=v[k][i][j-1];
            }
        }
        
    }
    for(int k=0;k<=c;k++){
        for(int j=0;j<101;j++){
            for(int i=1;i<101;i++){
                v[k][i][j]+=v[k][i-1][j];
            }
        }
    }
    while (q--)
    {
        ll t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        ll ans=0;
        for(int k=0;k<=c;k++){
            ll tmp1=0;
            ll tmp2=0;
            ll tmp3=0;
            tmp1=v[k][x1-1][y2];
            tmp2=v[k][x2][y1-1];
            tmp3=v[k][x1-1][y1-1];
            ll tmp4=v[k][x2][y2]-tmp1-tmp2+tmp3;
            ans+=tmp4*((t+k)%(c+1));
        }
        cout<<ans<<endl;
    }
    
}  
int main(){     
    int t=1;
    // cin>>t;
    for(int j=0;j<t;j++)
    {
        solve();
    }
    
}
