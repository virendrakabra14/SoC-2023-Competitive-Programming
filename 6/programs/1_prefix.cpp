#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 3, 0, -2, 5};
    int n = a.size();
    vector<int> p(n);

    p[0] = a[0];
    for (int i=1; i<n; i++) {
        p[i] = p[i-1] + a[i];
    }

    cout << p[4] - p[1] << "\n";    // 0 + -2 + 5
}