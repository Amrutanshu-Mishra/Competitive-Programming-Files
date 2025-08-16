#include <bits/stdc++.h>
using namespace std;

struct manacher{
    vector<int>p;

    void run_manacher(string s){
        // cout<<s<<"\n";
        int n=s.length();
        p.assign(n,1);  
        int l=1, r=1;
        for(int i=1;i<n;i++){
            p[i] = max(0, min(r-i,l+r-i>=0 ? p[l+r-i] : INT32_MAX));
            // cout<<i<<" "<<l+r-i<<" "<<p[l+r-i]<<endl;
            while (i+p[i]<n && i-p[i]>=0 &&s[i+p[i]] == s[i-p[i]])
            {
                p[i]++;
            }
            if(i+p[i] > r){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }

    void build(string s){
        string t;
        for(auto v:s){
            t+=string("#")+v;
        }
        run_manacher(t+"#");
    }

    int getLongest(int cen, bool odd){
        int pos=2*cen+1+(!odd);
        return p[pos]+1;
    }

    bool checkPalin(int l, int r){
        if((r-l+1) <= getLongest((l+r)/2, l%2==r%2)){
            return 1;
        }
        return 0;
    }

    pair<int,int> getLongestSubstringPos(string s) {
        int center = 0, radius = 0;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] > radius) {
                radius = p[i];
                center = i;
            }
        }
        // Map back to original string indices
        int start = (center - radius + 1) / 2;
        return {start, radius - 1}; // radius-1 is length
    }
}m;

void solve()
{
    string s;
    cin>>s;
    manacher m;
    m.build(s);
    // auto [start, len] = m.getLongestSubstringPos(s);
    pair<int,int>p = m.getLongestSubstringPos(s);
    cout << s.substr(p.first, p.second) << "\n";
}
int main()
{
    int t;
    t=1;
    // cin >> t;
    for (int j = 0; j < t; j++)
    {
        solve();
    }
    return 0;
}
