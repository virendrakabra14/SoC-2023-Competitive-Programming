#include <bits/stdc++.h>
using namespace std;

struct tmp_struct {
    int x, y;
};

struct comp {
    inline bool operator()(const tmp_struct& s1, const tmp_struct& s2) {
        // `const` to prevent params from modification by sort algo
        // `&` to prevent copying the entire object

        // sort by x (asc), and then by y (desc)
        if(s1.x == s2.x) return s1.y > s2.y;
        return s1.x < s2.x;
    }
};

struct comp2 {
    inline bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1.size() < v2.size();
    }
};

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // precalc();
    
    // int t; cin>>t;
    // while(t--) solve();
    
    int i=0, j=1;

    tmp_struct a; a.x=i; a.y=j; i++; j--;
    tmp_struct b; b.x=i; b.y=j; i--; j--;
    tmp_struct c; c.x=i; c.y=j; i--; j--;
    tmp_struct d; d.x=i; d.y=j; i++; j--;
    
    tmp_struct m1[] = {a,b,c,d};
    int n = sizeof(m1)/sizeof(tmp_struct);

    for (int i=0; i<n; i++) {
        cout << m1[i].x << '\t' << m1[i].y << "\n";
    }
    cout<<"-------\n";

    sort(m1, m1+n, comp());

    for (int i=0; i<n; i++) {
        cout << m1[i].x << '\t' << m1[i].y << "\n";
    }

    // comp2 compares vectors by their sizes
    
}