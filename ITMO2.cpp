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
//If I had an hour to solve a problem I'd spend 55 minutes thinking about the problem and 5 minutes thinking about the solution.-Albert Einstien


// Figuring out the Nature of an Optimal Solution. One of the most important thing in problems imo.

// Solving subtasks of the original problem and then trying to extend/generalize your solution.

// Fixing a parameter and then trying to maximise the result with respect to that fixed parameter.

// Finding necessary and sufficient conditions. Sometimes, your necessary conditions themselves become sufficient, or vice versa.

// Identifying Lower and Upper bounds, and constructing them.

// Reducing a problem into smaller subproblems, commonly used with Dynamic Programming or Inductive Proofs.

// Considering the Decision Version of the Problem instead. Especially useful in Counting problems, where you need to count number of good subsequences for example.

// Formalizing the Problem
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
int get_bit(ll n,ll pos){
    return (n&(1LL<<pos))!=0;
}

bool checker(vll &arr,int n,ll mid,ll m){
    ll count=0;
    for (int i = 0; i < n; i++)
    {
        ll tmp_b=sqrtl(m/arr[i]);
        count+=tmp_b;
    }
    
}
void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vll>arr(n,vll(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    int i=0;
    int j=0;
    for (int k = 0; k < s.size(); k++)
    {
        if(s[k]=='D'){
            ll sum=0;
            for (int l = 0; l < m; l++)
            {
                sum+=arr[i][l];
            }
            arr[i][j]=-1*sum;
            i++;
        }
        else{
            ll sum=0;
            for (int l = 0; l < n; l++)
            {
                sum+=arr[l][j];
            }
            arr[i][j]=-1*sum;
            j++;
        }
    }
    ll sum=0;
    for (int l = 0; l < n; l++)
    {
        sum+=arr[l][j];
    }
    arr[i][j]=-1*sum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}    

int main(){ 
    int t;
    t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}