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

const int M = 1e9 + 7;

vector<int>s_tree(4*100005);

//building the tree
void build_st(vector<int>&a,int ind,int low,int high){
     if(low==high){
          s_tree[ind]=a[low];
          return;
     }
     int mid=(low+mid)/2;
     build_st(a,2*ind+1,low,mid);
     build_st(a,2*ind+2,mid+1,high);
     s_tree[ind]=max(s_tree[2*ind+1],s_tree[2*ind+2]);
}

int query(int ind,int low,int high,int l,int r){
     if(low>=l&&high<=r){
          return s_tree[ind];
     }
     if(high<l||low>r){
          return INT32_MIN;
     }
     int mid=(low+high)/2;
     int left=query(2*ind+1,low,mid,l,r);
     int right=query(2*ind+2,mid+1,high,l,r);
     return max(left,right);
}