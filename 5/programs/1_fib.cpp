#include <bits/stdc++.h>
using namespace std;

long long memo[50] = {0};    // some max no. taken

long long fibM(int n) {
    if(memo[n] != 0) {         // check in memo
        return memo[n];
    }
    else {
        memo[n] = fibM(n-1) + fibM(n-2);    // if not present, make entry in memo
        return memo[n];
    }
}

long long fibT(int n) {
    vector<long long> table(n+1);
    table[0] = table[1] = 1;
    for (int i = 2; i < n+1; i++) {
        table[i] = table[i-1] + table[i-2];
    }
    return table[n];
}


int main() {

    int n; cin>>n;

    memo[0] = memo[1] = 1;

    cout << fibM(n) << '\t' << fibT(n);    
    
}