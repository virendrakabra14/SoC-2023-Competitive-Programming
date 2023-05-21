#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,m,src; cin>>n>>m>>src;     // n=|V|, m=|E|

    vector<int> dist(n, INT_MAX/2);     // initial distances from source: INF
    vector<int> prev_dist;
    vector<pair<pair<int,int>,int>> edges;      // edge list representation with weights

    edges.resize(2*m);      // undirected

    int u, v, w;
    for (int i=0; i<2*m; i+=2) {
        cin>>u>>v>>w;
        u--; v--;
        edges[i]={{u,v},w};
        edges[i+1]={{v,u},w};
    }

    dist[src] = 0;

    for (int i=0; i<n; i++) {       // will stabilize in at most n-1 rounds,
                                    // last round for checking negative cycle
        prev_dist=dist;     // check if stabilized

        bool stable=1;

        // iterate over all edges in each round
        for (auto e:edges) {
            u = e.first.first;
            v = e.first.second;
            w = e.second;
            
            dist[u]=min(dist[u],dist[v]+w);     // INT_MAX+w will be large negative; hence dist initialized with INT_MAX/2
            
            if(dist[u]<prev_dist[u]) {
                stable=0;
                if(i==n-1) {
                    cout << "neg cycle\n";
                    return 0;
                }
            }
        }

        if(stable) {
            cout << i+1 << " rounds\n";
            break;
        }

    }

    for (int i=0; i<n; i++) {
        cout << i << ' ' << dist[i] << '\n';
    }

}

/*
5 7 0
1 3 1
1 2 2
1 4 7
3 4 3
2 4 3
2 5 5
4 5 2
-----
4 5 0
1 2 3
1 3 5
2 3 2
3 4 -7
4 1 2
-----
(book graphs)
*/