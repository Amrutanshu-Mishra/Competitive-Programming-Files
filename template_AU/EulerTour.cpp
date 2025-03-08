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

// Flattening a tree into an array to easily query and update subtrees.
template <class T>
class BIT
{
private:
     int size;
     vector<T> bit;
     vector<T> arr;

public:
     BIT(int size) : size(size), bit(size + 1), arr(size) {}

     void set(int ind, int val) { add(ind, val - arr[ind]); }

     void add(int ind, int val)
     {
          arr[ind] += val;
          ind++;
          for (; ind <= size; ind += ind & -ind)
          {
               bit[ind] += val;
          }
     }

     T pref_sum(int ind)
     {
          ind++;
          T total = 0;
          for (; ind > 0; ind -= ind & -ind)
          {
               total += bit[ind];
          }
          return total;
     }
};

vector<vector<int>> neighbors;
vector<int> start;
vector<int> end;
int timer = 0;

void euler_tour(int at, int prev)
{
     start[at] = timer++;
     for (int n : neighbors[at])
     {
          if (n != prev)
          {
               euler_tour(n, at);
          }
     }
     end[at] = timer;
}
