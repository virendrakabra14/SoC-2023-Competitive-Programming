#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m; cin >> n >> m;     // n=|V|, m=|E|

    vector<vector<int>> adj(n, vector<int>(0));

    int u,v;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> dist(n, 0);        // distances from source

    int src = 0;
    dist[src] = 0;

    queue<int> Q;
    visited[src] = 1;       // mark it visited
    Q.push(src);

    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();
        // visited[x] = 1;                // not here
                                          // e.g., a-b-c (a-c edge)
                                          // `b` pushed twice
        for (auto i:adj[x]) {
            if(!visited[i]) {
                visited[i] = 1;           // mark visited at time of push
                dist[i] = dist[x]+1;
                Q.push(i);
            }
        }
    }

    cout<<"---\n";
    for (int i=0; i<n; i++) {
        cout<<i+1<<' '<<dist[i]<<"\n";
    }

}

/*
6 6
1 2
1 4
2 3
2 5
5 6
3 6
(book diagram)
*/