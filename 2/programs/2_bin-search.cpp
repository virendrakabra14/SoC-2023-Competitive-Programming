#include <bits/stdc++.h>
using namespace std;

void binSearch(vector<int>& a, int target) {        // pass reference to avoid copies
                                                    // or pass pointer
    // assumes `a` to be sorted
    // iterative version is better than recursive one

    int n = a.size();
    int l = 0, r = n-1;
    int mid;

    while(l <= r) {
        cout << l << ' ' << r << "\n";

        mid = l+(r-l)/2;      // (l+r)/2 may cause overflow

        if(a[mid]==target) {
            cout << "Found " << target << " at " << mid << "\n";
            return;
        }
        else if(a[mid]>target) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    cout << target << " not found\n";

}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    vector<int> a = {2, 4, 5, 7, 9, 100, 2303};
    int target = 2303;

    binSearch(a, target);
    cout << "---\n";
    binSearch(a, target+1);
    
}