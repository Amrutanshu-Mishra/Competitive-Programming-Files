#include<bits/stdc++.h>
// #include<iostream>
// #include<iomanip>
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
ll merge(vector<ll> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    ll cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

ll mergeSort(vector<ll> &arr, int low, int high) {
    ll cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

ll count_inversions(vector<ll>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}



void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi pd(n,0);
    vi pk(n,0);
    pd[0]=(s[0]=='D');
    pk[0]=(s[0]=='K');
    loop(1,n){
        pd[i]=pd[i-1]+(s[i]=='D');
        pk[i]=pk[i-1]+(s[i]=='K');
    }
    int g1=gcd(pd[0],pk[0]);
    map<pair<int,int>,int>m1;
    m1[{pd[0]/g1,pk[0]/g1}]=1;
    set<pair<int,pair<int,int>>>st;
    st.insert({1,{pd[0]/g1,pk[0]/g1}});
    vi ans(n,0);
    ans[0]=1;
    loop(1,n){
        ll g2=gcd(pd[i],pk[i]);
        int p1=m1[{pd[i]/g2,pk[i]/g2}];
        st.erase({p1,{pd[i]/g2,pk[i]/g2}});
        p1++;
        m1[{pd[i]/g2,pk[i]/g2}]=p1;
        st.insert({p1,{pd[i]/g2,pk[i]/g2}});
        // int p2=(*st.rbegin()).first;
        ans[i]=p1;
    }
    loop(0,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}  
int main(){ 
    int t;
    cin>>t;
    // t=1;
    for(int j=0;j<t;j++)
    {
        solve();
    }
    
}