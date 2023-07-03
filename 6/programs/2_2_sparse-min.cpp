#include <bits/stdc++.h>
using namespace std;

void precompute_min(vector<vector<int>>& st, vector<int>& a) {
    int n = a.size();

    // base case: i=0 (length 2^i = 1 intervals)
    for (int j=0; j<n; j++) {
        st[0][j] = a[j];
    }

    for (int i=1; i<(int)st.size(); i++) {
        for (int j=0; j<n; j++) {
            st[i][j] = min(st[i-1][j], st[i-1][j + (1<<(i-1))]);
        }
    }
}

int query_min(vector<vector<int>>& st, int l, int r) {
    int length = r-l+1;
    int lg_floor = 0;
    while((1 << lg_floor) <= length) {      // can be precomputed; O(1) queries
        lg_floor++;
    }
    return min(st[lg_floor][l], st[lg_floor][r-(1<<lg_floor)+1]); // intervals overlap; idempotence
}

int main() {
    vector<int> a = {1, 3, 0, -2, 5};
    int n = a.size();

    vector<vector<int>> st(2, vector<int>(n, 0));
    precompute_min(st, a);

    int l=1, r=3;
    cout << query_min(st, l, r) << "\n";
}