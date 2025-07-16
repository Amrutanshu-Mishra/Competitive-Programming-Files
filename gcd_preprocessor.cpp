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
vector<vll> gc;
void solve(){
}  
int main(){ 

    //this will preprocess all the possible gcds up until n in O(n^2)
    //works if n <=5000
    gc = vector<vll>(5001,vll(5001));
    for(int i=0;i<5001;i++){
        gc[i][0]=gc[0][i]=gc[i][i]=i;
    }
    for(int x=1;x<=5000;x++){
        for(int y=1;y<x;y++){
            gc[x][y] = gc[y][x] = gc[y][x%y];
        }
    }
}