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

int spf[200001];

void seive()
{
    for (int i = 0; i <= 200000; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i <= 200000; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= 200000; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vll arr(n);
    loop(0, n)
    {
        cin >> arr[i];
    }
}
int main()
{
    seive();
}
