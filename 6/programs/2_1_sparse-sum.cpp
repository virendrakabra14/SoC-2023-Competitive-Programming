#include <bits/stdc++.h>
using namespace std;

void precompute_sum(vector<vector<int>>& st, vector<int>& a) {
    int n = a.size();

    // base case: i=0 (length 2^i = 1 intervals)
    for (int j=0; j<n; j++) {
        st[0][j] = a[j];
    }

    for (int i=1; i<(int)st.size(); i++) {
        for (int j=0; j<n; j++) {
            st[i][j] = st[i-1][j] + st[i-1][j + (1<<(i-1))];
        }
    }
}

int query_sum(vector<vector<int>>& st, int l, int r) {
    int sum = 0;
    int length = r-l+1;
    for (int i=(int)st.size(); i>=0; i--) {   // iterate over powers of 2
        if((1<<i) <= length) {
            sum += st[i][l];
            l += (1<<i);
        }
    }
    return sum;
}

int main() {
    vector<int> a = {1, 3, 0, -2, 5};
    int n = a.size();

    vector<vector<int>> st(2, vector<int>(n, 0));
    precompute_sum(st, a);

    int l=1, r=3;
    cout << query_sum(st, l, r) << "\n";
}