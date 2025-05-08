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
    string s;
    cin>>s;
    vector<int>ans;
    string base="LIT";
    if(count(s.begin(),s.end(),s[0])==n){
        cout<<-1<<endl;
        return;
    }
    while (true)
    {
    
        vector<pair<int,char>>cnt;
        for(auto i:base){
            cnt.push_back({count(s.begin(),s.end(),i),i});
        }
        sort(cnt.begin(),cnt.end());
        if(cnt[0].first==cnt[1].first && cnt[1].first==cnt[2].first){
            break;
        }
        //first time writing a lambda function
        auto op =[&] (int i)->void{
            string z=base;
            z.erase(find(z.begin(),z.end(),s[i]));
            z.erase(find(z.begin(),z.end(),s[i+1]));
            ans.push_back(i);
            s=s.substr(0,i+1)+z[0]+s.substr(i+1);
        };

        bool done=false;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                continue;
            }
            if(s[i]!=cnt[0].second && s[i+1]!=cnt[0].second){
                op(i);
                done=true;
                break;
            }
        }
        if(done) {
            continue;
        }   
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                continue;
            }
            //now trying for substrings ca or ac
            if(s[i]==cnt[2].second){
                op(i);
                op(i+1);
                op(i);
                op(i+2);
                break;
            }
            else if(s[i+1]==cnt[2].second){
                op(i);
                op(i);
                op(i+1);
                op(i+3);
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i+1<<endl;
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
