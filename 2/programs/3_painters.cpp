#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>& a, int numP, int n) {
    // try mid
    int index = 0;        // index into a, to know how many walls covered
    for (int i=0; i<numP; i++) {
        int sum = 0;
        while(sum+a[index] <= mid && index < n) {       // sum+a[index] <= mid, as no painter should take time >mid
            sum += a[index];
            index++;
        }
    }
    return index >= n;
}

void solve(vector<int>& a, int numP) {
    
    int n = a.size();
    int tot = 0;

    for (int i=0; i<n; i++) {
        tot += a[i];
    }

    int l = 0, r = tot;         // could just use r = INT_MAX, instead of computing tot
    int mid = l+(r-l)/2;
    int ans = mid;

    while(l <= r) {
        cout << l << '\t' << mid << '\t' << r << "\n";      // can see O(log(tot)) iterations
        mid = l+(r-l)/2;

        if(check(mid, a, numP, n)) {    // `mid` works; discard the right half
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    cout << ans << "\n";

}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    vector<int> a = {9, 4, 7, 10, 5};
    int numP = 3;
    solve(a, numP);
    
}