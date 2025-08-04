#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define loop(j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ll> vll;
const int M = 1000000007;

class Solution {
public:
    bool checker(vector<int>& fruits,int mid){
        set<int>st;
        map<int,int>freq;
        for(int i=0;i<mid;i++){
            freq[fruits[i]]++;
            st.insert(fruits[i]);
        }
        if(st.size()<=2){
            return true;
        }
        int j=0;
        for(int i=mid;i<fruits.size();i++){
            freq[fruits[j]]--;
            freq[fruits[i]]++;
            if(freq[fruits[j]]==0){
                st.erase(fruits[j]);
            }
            st.insert(fruits[i]);
            j++;
            if(st.size()<=2){
                return true;
            }
        }
        return false;
    }
    int totalFruit(vector<int>& fruits) {
        int s=1;
        int e=fruits.size();
        int ans=s;
        while(s<=e){
            int mid=(s+e)/2;
            if(checker(fruits,mid)){
                ans=max(ans,mid);
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};

void helper(ll n, ll tmp,ll &ans){
    if(n*1000<tmp){
        return;
    }
    if(tmp>=n){
        ll tmp2=tmp;
        // cout<<tmp<<endl;
        int sc=0;
        int fc=0;
        while (tmp2>0)
        {
            int tmp3=tmp2%10;
            tmp2=tmp2/10;
            if(tmp3==4){
                fc++;
                continue;
            }
            if(tmp3==7){
                sc++;
                continue;
            }
        }
        if(sc==fc){
            // cout<<
            ans=min(ans,tmp);
        }
        helper(n,tmp*10+7,ans);
        helper(n,tmp*10+7,ans);
        return;
    }
    helper(n,tmp*10+4,ans);
    helper(n,tmp*10+7,ans);
}

void solve()
{
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<" "<<0<<endl;
        return;
    }
    ll g=abs(a-b);
    ll ans=min(a%g,g-a%g);
    cout<<g<<" "<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}