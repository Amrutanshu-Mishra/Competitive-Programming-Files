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
class Solution {
public:
    static bool hamming1(string& s, string& t){
        const int sz=s.size();
        if (sz!=t.size()) return 0;
        int diff=0;
        for (int i=0; i<sz && diff<2; i++)
            diff+=s[i]!= t[i];
        return diff== 1;
    }

    static vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n=words.size();
        int maxLen=0, pos=-1;
        int* dp=(int*)alloca(n*4);
        fill(dp, dp+n, 1);
        int* prev=(int*)alloca(n*4);
        fill(prev, prev+n, -1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(groups[i]!=groups[j] && hamming1(words[i], words[j]) 
                && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                pos=i;
            }
        }
        vector<string> ans(maxLen);
        for(; pos!=-1; pos=prev[pos]){
            ans[--maxLen]=words[pos];
        }
        return ans;
    }
};
void solve(){
   int n;
   cin>>n;
   vll arr(n);
   loop(0,n){
    cin>>arr[i];
   }
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
