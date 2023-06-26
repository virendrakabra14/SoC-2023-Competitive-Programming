#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull Choose(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1));

    // base cases
    for (int j=1; j<k+1; j++) {
        dp[0][j]=0;             // 0Cj
    }
    for (int i=0; i<n+1; i++) {
        dp[i][0]=1;             // iC0
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<k+1; j++) {
            dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
        }
    }

    return dp[n][k];
}

int main() {
    int n,k;
    cin >> n >> k;
    cout << Choose(n,k) << '\n';
}