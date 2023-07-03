#include <bits/stdc++.h>
using namespace std;

int default_val = 0;

int merge(int a, int b) {
    return a+b;
}

int getMid(int l, int r) {
    return l+(r-l)/2;
}

void build(vector<int>& t, vector<int>& a, int si, int l, int r) {
    // si indexes into the segment-tree array (t)
    // l and r index into the underlying input array (a)

    if(l == r) {
        t[si] = a[l];
        return;
    }

    int mid = getMid(l,r);
    build(t, a, 2*si+1, l, mid);            // t[0]
    build(t, a, 2*si+2, mid+1, r);

    t[si] = merge(t[2*si+1], t[2*si+2]);
}

void update(vector<int>& t, int si, int l, int r, int i, int new_val) {
    // l, r, and i index into array a
    // t[si] is the result of a[l...r]; update is a[i] = new_val

    if(i < l || i > r) {
        return;
    }

    if(l == r) {
        t[si] = new_val;
        return;
    }

    int mid = getMid(l,r);
    update(t, 2*si+1, l, mid, i, new_val);
    update(t, 2*si+2, mid+1, r, i, new_val);

    t[si] = merge(t[2*si+1], t[2*si+2]);

}

int query(vector<int>& t, int si, int l, int r, int ql, int qr) {
    // l, r, ql, qr index into array a

    if(ql > r || qr < l) {      // [2,4] l,r => [5,7]
                                // l,r=[3,4], ql,qr=[6,8]
        return default_val;
    }

    if(l >= ql && r <= qr) {    // ql,qr = [5,10], l,r = [6,8]
        return t[si];
    }

    int mid = getMid(l,r);
    return merge(query(t, 2*si+1, l, mid, ql, qr), query(t, 2*si+2, mid+1, r, ql, qr));

}

int main() {

    vector<int> a {3, -32, 23, -865, 63, -45, 0, 86, 5};
    int n = a.size();

    vector<int> t(4 * n);   // array for tree
    build(t, a, 0, 0, n-1); // t[0] (root of seg-tree) holds value for a[l..r]=a[0..n-1]

    cout << query(t, 0, 0, n-1, 3, 7) << "\n";

}