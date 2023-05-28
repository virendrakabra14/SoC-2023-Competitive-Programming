#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int,int>, int> edge_type;     // (u,v) w

vector<edge_type> edges;     // edge list representation
vector<int> parent;
vector<int> sizes;

struct sort_edges {
    inline bool operator() (const edge_type& edge1, const edge_type& edge2) {
        return edge1.second < edge2.second;
    }
};

void make_set(int v) {
    parent[v] = v;
    sizes[v] = 1;
}

int get(int v) {
    if (v==parent[v]) return v;
    parent[v] = get(parent[v]);     // assignment: path compression
    return parent[v];
}

void union_sets(int a, int b) {     // union by size heuristic
    a = get(a);
    b = get(b);
    if(a != b) {                    // don't union if in same sets
        if(sizes[a] < sizes[b]) swap(a,b);
        parent[b] = a;              // merge smaller into larger
        sizes[a] += sizes[b];
    }
}

int main() {

    edges.clear();
    parent.clear();

    int n, m;
    cin>>n>>m;

    edges.resize(m);
    parent.resize(n);
    sizes.resize(n);

    for (int i=0; i<n; i++) {
        make_set(i);
    }

    int u, v, w;      // (u,v) with weight w;
    for (int i=0; i<m; i++) {
        cin>>u>>v>>w;
        u--; v--;
        edges[i] = {{u,v},w};
    }

    sort(edges.begin(), edges.end(), sort_edges());     // sorts edges in ascending order of weights

    vector<edge_type> mst_edges(0);

    for (int i=0; i<m; i++) {                   // iterate over all edges
        if(mst_edges.size() == n-1) break;      // |V|-1
        u = edges[i].first.first;
        v = edges[i].first.second;
        w = edges[i].second;
        if (get(u) != get(v)) {
            mst_edges.push_back(edges[i]);
            union_sets(u,v);
        }
    }

    int weight = 0;

    for (int i=0; i<n-1; i++) {
        cout << mst_edges[i].first.first+1 << ' ' << mst_edges[i].first.second+1 << '\n';
        weight += mst_edges[i].second;
    }
    cout << weight << '\n';

}