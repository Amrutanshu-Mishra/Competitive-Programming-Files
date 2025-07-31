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

string res;

bool check(string &pref,string &suf,int n,vector<string>&v){
    string s=pref+suf.substr(n-2);
    multiset<string>vv,sPref,sSuf;
    for(int i=0; i<n-1; i++){
        sPref.insert(s.substr(0,n-i-1));
        vv.insert(s.substr(0,n-i-1));
        sSuf.insert(s.substr(i+1));
        vv.insert(s.substr(i+1));
    }

    if(vv==multiset<string>(v.begin(),v.end())){
        for(int i=0;i<2*n-2;i++){
            if(sPref.count(v[i])){
                res+='P';
                sPref.erase(sPref.find(v[i]));
            }
            else if(sSuf.count(v[i])){
                res+='S';
                sSuf.erase(sSuf.find(v[i]));
            }
            else{
                return false;
            }
        }
        return true;
    }
    return false;
}

void solve()
{
    int n;
    cin>>n;
    vector<string>v;
    vector<string>v2;
    loop(0,2*n-2){
        string s;
        cin>>s;
        if(s.size()==n-1){
            v2.push_back(s);
        }
        v.push_back(s);
    }
    if(check(v2[0],v2[1],n,v)){
        cout<<res<<endl;
    }
    else{
        check(v2[1],v2[0],n,v);
        cout<<res<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}