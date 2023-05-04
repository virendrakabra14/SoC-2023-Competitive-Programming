#include <bits/stdc++.h>
using namespace std;

int main() {

    pair<int,char> p(1, 'a');
    cout << p.first << ' ' << p.second<<"\n";

    p = make_pair(1,'a');
    p = {1,'a'};

    map<int,int> m1;
    m1.insert({1,10});
    m1.insert({3,20});
    m1.insert({-1,100});
    m1[-10] = 1000;
    m1[-10] = 1000;     // only one entry per key
    // use multimap if distinct elements with same key are required

    // erase by key
    m1.erase(1);

    for (map<int, int>::iterator it=m1.begin(); it!=m1.end(); it++) {
        cout<<it->first<<'\t'<<it->second<<"\n";
    }
    // more convenient:
    // for (auto&& p: m1) {
    //     cout << p.first << '\t' << p.second << "\n"; 
    // }

    // find by key
    // returns iterator to element if found, else iterator to map.end() (position AFTER end of map)
    cout << (m1.find(3)!=m1.end() ? "found" : "not found") << "\n";
    cout << (m1.count(3) ? "found" : "not found") << "\n";
    cout << m1[3] << "\n";
    cout << "default value: " << m1[-101] << "\n";       // default value

    // map: ordered

    // use unordered_map when order isn't required
    // fast search, insert, delete operations
    // unordered_map<int, int>

    // example
    // given an array and a target sum, is there a pair of integers that add up to the target sum

    vector<int> v{1, 2, 5, 4, 3, -1, 10};
    int target = 8;

    // M1: iterate over all pairs: O(n^2)
    for (int i=0; i<(int)v.size(); i++) {
        bool done=false;
        for (int j=0; j<(int)v.size(); j++) {
            if (v[i]+v[j] == target) {
                cout << "M1: " << v[i] << ' ' << v[j] << "\n";
                done=true;
            }
        }
        if (done) {break;}
    }

    // M2: sort, and use two-pointers approach
    vector<int> v_copy = v;
    sort(v_copy.begin(), v_copy.end());     // {-1, 1, 2, 3, 4, 5, 10}
    int l = 0, r = v_copy.size()-1;
    while(l < r) {
        if(v_copy[l] + v_copy[r] == target) {
            cout << "M2: " << v_copy[l] << ' ' << v_copy[r] << '\n';
            break;
        }
        else if(v_copy[l] + v_copy[r] > target) {
            r--;
        }
        else {
            l++;
        }
    }

    // M3: search for complement (target-v[i])
    // need a data structure that has small lookup time
    // not a vector or map, but an unordered_map
    // but keys NOT required, so unordered_set works!

    unordered_set<int> set1;
    for (int i=0; i<(int)v.size(); i++) {
        if (set1.find(target-v[i]) != set1.end()) {
            cout<<"M3: " << v[i] << ' ' << target-v[i] << "\n";
            break;
        }
        else {
            set1.insert(v[i]);
        }
    }

    // lower_bound
    // upper_bound
    // https://www.geeksforgeeks.org/set-in-cpp-stl/

    set<int> set2;
    set2.insert(1);
    set2.insert(1);
    set2.insert(2);
    for (auto&& i: set2) {
        cout << i << " ";
    }
    cout<<"\n";


}