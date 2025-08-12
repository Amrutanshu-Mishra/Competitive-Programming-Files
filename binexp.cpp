#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;

long long binexp(long long a,long long b,long long m){
    long long result=1;
    while(b>0){
        if(b&1){
            result=(result*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b>>=1;
    }
    return result;
}