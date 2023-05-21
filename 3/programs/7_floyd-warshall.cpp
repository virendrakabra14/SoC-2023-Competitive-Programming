#include <bits/stdc++.h>
using namespace std;

#define INF 1e7

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INF));     // adjacency matrix

    for (int i=0; i<n; i++) {
        dist[i][i] = 0;
    }

    int u, v, w;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

}

/*
5 6
1 2 5
1 4 9
1 5 1
2 3 2
3 4 7
4 5 2
*/