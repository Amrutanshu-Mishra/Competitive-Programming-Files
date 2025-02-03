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
void solve(){
     int n;
     cin>>n;
     vll arr(n);
     loop(0,n){
          cin>>arr[i];
     }
     map<ll,int>m1;
     loop(0,n){
          m1[arr[i]]++;
     }
     vll a;
     for(auto i:m1){
          if(i.second>1){
               a.push_back(i.first);
          }
     }
     sort(a.begin(),a.end());
     int n1=a.size();
     if(a.size()>=4){
        cout<<"YES"<<endl;
        cout<<a[0]<<" "<<a[1]<<" "<<a[n1-2]<<" "<<a[1]<<" "<<a[0]<<" "<<a[n1-1]<<" "<<a[n1-2]<<" "<<a[n1-1]<<endl;
        return;
     }
     for(int i=0;i<a.size();i++){
          vector<int>tmp;
          if(m1[a[i]]>=4){
               // cout<<"He"<<endl;
               int x=m1[a[i]];
               for(int j=0;j<n;j++){
                    if(arr[j]==a[i]){
                         continue;
                    }
                    tmp.push_back(a[i]);
                    tmp.push_back(arr[j]);
                    x--;
                    if(x==0){
                         break;
                    }
               }
               // for(auto j:tmp){
               //      cout<<j<<" ";
               // }
               // cout<<endl;
               while(x--){
                    tmp.push_back(a[i]);
               }
               if(tmp.size()>=8){
                    cout<<"YES"<<endl;
                    for(int j=0;j<8;j++){
                         cout<<tmp[j]<<" ";
                    }
                    cout<<endl;
                    return;
               }
               tmp.clear();
          }
     }
     cout<<"NO"<<endl;
}  
int main(){ 
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        solve();
    }
    return 0;
}