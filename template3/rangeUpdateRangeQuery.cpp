#include <bits/stdc++.h>
using namespace std;

template <class T> class BIT {
  private:
    int size;
    vector<T> bit;
    vector<T> arr;

  public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    void set(int ind, T val) { add(ind, val - arr[ind]); }

    void add(int ind, T val) {
        arr[ind] += val;
        ind++;
        for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
    }

    T pref_sum(int ind) {
        ind++;
        T total = 0;
        for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
        return total;
    }

    // Range sum query for [l, r]
    T range_sum(int l, int r) {
        return pref_sum(r) - (l > 0 ? pref_sum(l - 1) : 0);
    }
};

int main() {
    int n = 5;
    BIT<int> fenwick(n); // Create a BIT for 'n' elements

    // Initialize array with values
    vector<int> arr = {1, 2, 3, 4, 5}; 

    // Construct BIT
    for (int i = 0; i < n; i++) {
        fenwick.add(i, arr[i]); // Add elements one by one
    }

    // Get prefix sum of first 3 elements (index 0 to 2)
    cout << "Prefix Sum (0 to 2): " << fenwick.pref_sum(2) << endl;

    // Get sum of range [1, 4]
    cout << "Range Sum (1 to 4): " << fenwick.range_sum(1, 4) << endl;

    // Update value at index 2 to 10
    fenwick.set(2, 10);

    // Get prefix sum after update
    cout << "Prefix Sum (0 to 2) after update: " << fenwick.pref_sum(2) << endl;

    return 0;
}