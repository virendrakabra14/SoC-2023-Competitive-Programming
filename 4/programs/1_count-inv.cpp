#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& a1, vector<int>& a2, vector<int>& a) {
    // same as mergesort

    int i=0, j=0;
    int inv=0;
    int n1=a1.size(), n2=a2.size();
    while(i<n1 || j<n2) {
        if(i>=n1) {
            for (; j<n2; j++) {
                a[i+j]=a2[j];
            }
            break;
        }
        else if(j>=n2) {
            for(; i<n1; i++) {
                a[i+j]=a1[i];
            }
            break;
        }
        else {
            if(a1[i]>a2[j]) {
                inv += n1-i;
                a[i+j]=a2[j];
                j++;
            }
            else {
                a[i+j]=a1[i];
                i++;
            }
        }
    }
    return inv;
}

int count_inv(vector<int>& a) {
    
    if(a.size()==1) return 0;

    int mid = a.size()/2;
    vector<int> a1(a.begin(),a.begin()+mid);    // element mid not taken here
                                                // note: if mid taken in first and not in second, 
                                                // then leads to infinite recursion in, e.g., a = {2, 1}.
    vector<int> a2(a.begin()+mid,a.end());

    // recursion
    int n1=count_inv(a1);
    int n2=count_inv(a2);

    return n1 + n2 + merge(a1,a2,a);

}

int main() {
    
    int n; cin>>n;
    vector<int> a(n);
    
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    cout<<count_inv(a);

}