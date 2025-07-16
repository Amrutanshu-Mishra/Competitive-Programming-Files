// #include<bits/stdc++.h>
// using namespace std;

// typedef long long lli;
// typedef unsigned long long ull;
// typedef long double lld;
// #define MOD 1000000007
// #define INF 1e18
// #define PI 3.141592653589793238462
// #define LLI_MAX LLONG_MAX
// #define LLI_MIN LLONG_MIN
// #define vi vector<lli>
// #define vvi vector<vector<lli>>
// #define vp vector<pair<lli, lli>>
// #define pb push_back
// #define endl "\n"
// #define sz(x) ((lli)(x).size())
// #define all(x) (x).begin(), (x).end()
// #define set_bits __builtin_popcountll
// #define precision(x) fixed<<setprecision(x)
// #define f(i, n) for(lli i=0; i<n; i++)
// #define r(i, n) for(lli i=n-1; i>=0; i--)
// #define iv(a, n) for(lli i=0; i<n; i++) cin>>a[i]
// #define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// template <class T> using maxHeap = priority_queue<T>;
// template <class T> using minHeap = priority_queue<T, vector<T>, greater<T>>;

// #ifdef ONLINE_JUDGE
//     #define debug(x)
// #else
//     #define debug(x) cerr<<#x<<" -> "; _print(x); cerr<<endl;
// #endif

// template<class T> void _print(vector<T> v){
//     cerr<<"{";
//     for(T i: v){
//         cerr<<i<<", ";
//     }
//     cerr<<"}";
// }
// template<class T> void _print(T x) { cerr<<x; }



// void solve(){
//     lli n;
//     cin>>n;

//     lli minx=LLI_MAX, miny=LLI_MAX, maxx=LLI_MIN, maxy=LLI_MIN;

//     vp v(n);
//     map<lli, lli> row;
//     map<lli, lli> col;
//     f(i, n){
//         cin>>v[i].first>>v[i].second;
//         row[v[i].first]++;
//         col[v[i].second]++;
//         minx = min(minx, v[i].first);
//         miny = min(miny, v[i].second);
//         maxx = max(maxx, v[i].first);
//         maxy = max(maxy, v[i].second);
//     } 
//     lli area = (maxx-minx+1)*(maxy-miny+1);

//     if(area==n){
//         cout<<area<<endl;
//         return;
//     }
//     lli ans = area;
//     for(lli i=0; i<n; i++){
//         lli x = v[i].first, y = v[i].second;
//         if(x!=minx && x!=maxx && y!=miny && y!=maxy) continue;
//         else{
//             if(row[x]==1 || col[y]==1){
//                 // cout<<x<<" "<<y<<endl;
//                 lli min1x=LLI_MAX, min1y=LLI_MAX, max1x=LLI_MIN, max1y=LLI_MIN;
//                 f(j, n){
//                     if(j==i) continue;
//                     min1x = min(min1x, v[j].first);
//                     min1y = min(min1y, v[j].second);
//                     max1x = max(max1x, v[j].first);
//                     max1y = max(max1y, v[j].second);
//                 } 
//                 lli a = (max1x-min1x+1)*(max1y-min1y+1);
//                 if(a==n-1){
//                     a = min(a+(max1x-min1x+1), a+(max1y-min1y+1));
//                 }
//                 ans = min(ans, a);
//             }
//         }
//     }
//     cout<<ans<<endl;

// }



// int main(){
// #ifndef ONLINE_JUDGE
//     freopen("Error.txt", "w", stderr);
//     clock_t T = clock();
// #endif
//     fastio();
    
//     lli t;
//     cin>>t;

//     while(t--){
//         solve();
//     }

// #ifndef ONLINE_JUDGE
//     cerr<<"\nTime taken: "<<((float)(clock()-T))/CLOCKS_PER_SEC<<"seconds";
// #endif
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef unsigned long long ull;
typedef long double lld;
#define MOD 1000000007
#define INF 1e18
#define PI 3.141592653589793238462
#define LLI_MAX LLONG_MAX
#define LLI_MIN LLONG_MIN
#define vi vector<lli>
#define vvi vector<vector<lli>>
#define vp vector<pair<lli, lli>>
#define pb push_back
#define endl "\n"
#define sz(x) ((lli)(x).size())
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define precision(x) fixed<<setprecision(x)
#define f(i, n) for(lli i=0; i<n; i++)
#define r(i, n) for(lli i=n-1; i>=0; i--)
#define iv(a, n) for(lli i=0; i<n; i++) cin>>a[i]
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
template <class T> using maxHeap = priority_queue<T>;
template <class T> using minHeap = priority_queue<T, vector<T>, greater<T>>;

#ifdef ONLINE_JUDGE
    #define debug(x)
#else
    #define debug(x) cerr<<#x<<" -> "; _print(x); cerr<<endl;
#endif

template<class T> void _print(vector<T> v){
    cerr<<"{";
    for(T i: v){
        cerr<<i<<", ";
    }
    cerr<<"}";
}
template<class T> void _print(T x) { cerr<<x; }

x1,y1
x2,y2


xn,yn
xmax-min+1 * ymax-ymin+1
1111
void solve(){
    lli n;
    cin>>n;
    vector<lli> x(n), y(n);
    vp points(n);
    f(i, n) {
        cin >> x[i] >> y[i];
        points[i] = {x[i], y[i]};
    }

    auto x_sorted = x, y_sorted = y;
    sort(all(x_sorted));
    sort(all(y_sorted));

    lli area = (x_sorted[n-1]-x_sorted[0]+1)*(y_sorted[n-1]-y_sorted[0]+1);
    if(area==n){
        cout<<area<<endl;
        return;
    }
    lli ans = area;
    f(i, n){
        lli xi=points[i].first, yi=points[i].second;

        bool f = (xi==x_sorted[0] || xi==x_sorted[n-1] || yi==y_sorted[0] || yi==y_sorted[n-1]);
        if(!f) continue;

        lli minx = (xi==x_sorted[0])? x_sorted[1]:x_sorted[0];
        lli maxx = (xi==x_sorted[n-1])? x_sorted[n-2]:x_sorted[n-1];
        lli miny = (yi==y_sorted[0])? y_sorted[1]:y_sorted[0];
        lli maxy = (yi==y_sorted[n-1])? y_sorted[n-2]:y_sorted[n-1];
        lli a = (maxx-minx+1)*(maxy-miny+1);
        if(a==n-1){
            a = min(a+(maxx-minx+1), a+(maxy-miny+1));
        }
        ans = min(ans, a);
    }

    cout<<ans<<endl;
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    clock_t T = clock();
#endif
    fastio();
    
    lli t;
    cin>>t;

    while(t--){
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr<<"\nTime taken: "<<((float)(clock()-T))/CLOCKS_PER_SEC<<"seconds";
#endif
    return 0;
}