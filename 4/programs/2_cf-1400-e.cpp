#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int l, int r) {
    // base case or condition to stop recursion
    if(l > r) return 0;

    // find minimum, and make it zero with type_1 ops
    auto min_it = min_element(a.begin()+l, a.begin()+(r+1));
    int min_val = *min_it;

    for (int i=l; i<=r; i++) {
        a[i] -= min_val;
    }

    // two choices
    return min(solve(a, l, min_it-a.begin()-1) + min_val + solve(a, min_it-a.begin()+1, r), r-l+1);
}

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << solve(a, 0, n-1);
}