#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define modN 1000000007

ll fast_exp_mod(ll x, ll y) {
    // x**y

    /**
     * Example: 3**13 = 3**(1101)
     * Set bit positions 0, 2, 3
     * 3**8 * 3**4 * 3**1
    */

    ll ans = 1;
    while(y > 0) {
        if(y&1) {   // LSB of y is 1
            ans *= x;
            ans %= modN;
        }
        y >>= 1;
        x *= x;
        x %= modN;
    }
    return ans;
}

ll inv_mod(ll x) {
    x %= modN;
    return fast_exp_mod(x, modN-2);
}

vector<ll> factorials_mod(1000);
void compute_fact_mod() {
    factorials_mod[0] = 1;      // 0!
    for (int i=1; i<int(factorials_mod.size()); i++) {
        factorials_mod[i] = factorials_mod[i-1]*i;
        factorials_mod[i] %= modN;
    }
}

ll nCr_mod(ll n, ll r) {
    // n! / (n-r)!r!
    if(r>n) return -1;

    ll ans = 1;
    ans *= factorials_mod[n];
    ans *= inv_mod(factorials_mod[n-r]);    ans %= modN;
    ans *= inv_mod(factorials_mod[r]);      ans %= modN;

    return ans;
}

int main() {
    cout<<fast_exp_mod(2,20)<<' '<<fast_exp_mod(3,6)<<'\n';

    compute_fact_mod();
    cout << nCr_mod(5,2) << ' ' << nCr_mod(100,7) << '\n';
}