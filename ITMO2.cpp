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

vector<vll> gc;

void solve(){
    int n;
    cin>>n;
    vi arr(n);
    loop(0,n){
        cin>>arr[i];
    }

    //first thing to observe is that the value(say x) which will be the value at all the index of the arr
    //at the end will always be equal to the the gcd of the elements in the array(we will refer to this value as g1)
    //so if the arr alrady contains g1 then we just count its frequency and our answer is n-cnt
    int g1=arr[0];
    loop(1,n){
        g1=gcd(g1,arr[i]);
    }
    int cnt=0;
    loop(0,n){
        if(arr[i]==g1){
            cnt++;
        }
    }
    if(cnt){
        cout<<n-cnt<<endl;
        return;
    }


    //but if the arr doesnt contain value of g1 thats when things get tricky
    //we use dp where mi[i] = minimum number of operations required to have at least one i in the arr
    //now we use multi source bfs
    //initially dp[arr[i]] = 0 for all i from 0 to n-1

    vi mi(5001,INT_MAX);
    queue<int>q;
    loop(0,n){
        mi[arr[i]]=0;
        q.push(arr[i]);
    }

    //then for every value in this queue we get its gcd with every other element in the arr
    //then dp[gcd(current_value,arr[i])]=1+dp[current_value]
    while (q.size())
    {
        int val = q.front();
        q.pop();

        for(auto x:arr){
            if(mi[gc[x][val]]==INT_MAX){
                mi[gc[x][val]] = 1 + mi[val];
                q.push(gc[x][val]);
            }
        }
    }
    

    //finally answer
    cout<< n + mi[g1] - 1<<endl;
}    

int main(){ 

    //since n and ai are 5000 only we can preprocess all the possible gcds that we need 
    gc = vector<vll>(5001,vll(5001));
    for(int i=0;i<5001;i++){
        gc[i][0]=gc[0][i]=gc[i][i]=i;
    }
    for(int x=1;x<=5000;x++){
        for(int y=1;y<x;y++){
            gc[x][y] = gc[y][x] = gc[y][x%y];
        }
    }
    int t;
    t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}