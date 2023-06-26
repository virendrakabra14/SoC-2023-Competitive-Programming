#include <bits/stdc++.h>
using namespace std;

void printParen(vector<vector<int>>& s, int i, int j) {
    if (i==j) {
        cout<<i;
        return;
    }
    if (i<j) {
        cout<<"(";
        printParen(s,i,s[i][j]);
        printParen(s,s[i][j]+1,j);
        cout<<")";
    }
}

void solve() {
    int n; cin>>n;
    vector<int> p(n+1);                      // matrix dimensions p[i] x p[i+1] for A_i
    for (int i=0; i<n+1; i++) {
        cin>>p[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    vector<vector<int>> s(n, vector<int>(n));

    // base cases:
    for (int i=0; i<n; i++) {
        dp[i][i] = 0;
    }

    for (int len=2; len<=n; len++) {          // length Ai...Aj
        for (int i=0; i<n; i++) {
            int j = len+i-1;
            if (j>=n) continue;
            for (int k=i; k<j; k++) {
                int temp = dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (dp[i][j] > temp) {
                    dp[i][j] = temp;
                    s[i][j] = k;      // storing k, to get the actual parenthesization later
                }
            }
        }
    }

    cout<<dp[0][n-1]<<"\n";
    printParen(s,0,n-1);

}

int main() {

    solve();

/*
4
40 20 30 10 30
*/

}