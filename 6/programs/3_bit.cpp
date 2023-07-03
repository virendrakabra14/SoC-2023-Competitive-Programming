#include <bits/stdc++.h>
using namespace std;

class BIT {

public:

    int n;
    vector<int> t;

    BIT(int n, int def=0) {
        t.clear();
        t.resize(n+1, def);
        this->n = n;
    }

    // returns sum of a[1..i] [1-indexed] -> [g(i),i] U [g(g(i)-1), g(i)-1] U ... U [0, ...]
    int query(int i) {      // [l,r] = query(r) - query(l-1)
        int ans = 0;
        while(i > 0) {
            ans += t[i];
            i -= (i&-i);        // i = g(i) - 1
        }
        return ans;
    }

    // adds x to a[i] [1-indexed]
    void increase(int i, int x) {
        while(i <= n) {
            t[i] += x;
            i += (i&-i);
        }
    }

};

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> a = {1, 3, 0, -2, 5};
    int n = a.size();

    BIT bit(n);

    for (int i=1; i<n+1; i++) {
        bit.increase(i, a[i-1]);        // 1-indexed
    }

    cout << bit.query(4) << '\n';       // ''

}