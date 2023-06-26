#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,W; cin>>n>>W;
    int w[n],p[n];              // weights and prices
    for (int i=0; i<n; i++) {
        cin>>w[i];
    }
    for (int i=0; i<n; i++) {
        cin>>p[i];
    }

    int dp[n+1][W+1];           // dp[i][j] = max price that we can get from first i items, and bag of capacity j

    // base cases:

    // i=0; if 0 items, then sum of prices of items taken = 0
    for (int j=0; j<W+1; j++) {
        dp[0][j]=0;
    }

    // j=0; if bag's capacity is 0, then price we can get = 0
    for (int i=0; i<n+1; i++) {
        dp[i][0]=0;
    }

    // fill array
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<W+1; j++) {
            if(j-w[i-1] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + p[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    /*--------------------------------*/

    // only 2 rows suffice
    int dp2[2][W+1];
    
    // base cases:
    // 0 items
    for (int j=0; j<W+1; j++) {
        dp2[0][j]=0;
    }
    // 0 capacity:
    for (int i=0; i<2; i++) {
        dp2[i][0]=0;
    }

    // now fill in:
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<W+1; j++) {
            if(j-w[i-1] >= 0) {
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-w[i-1]] + p[i-1]);
            }
            else {
                dp[i%2][j] = dp[(i-1)%2][j];
            }
        }
    }

    // required answer: dp2[n%2][W]

/*
4 8
3 4 6 5
2 3 1 4
*/
// optimal solution: first and last items

}