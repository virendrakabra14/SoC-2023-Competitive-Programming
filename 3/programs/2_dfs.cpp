#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int& time_counter,
         vector<int>& arrival, vector<int>& departure, vector<int>& parent) {

    arrival[node] = time_counter;
    time_counter++;

    for(auto i: adj[node]) {
        if(!visited[i]) {
            visited[i] = 1;

            // recurse
            dfs(i, adj, visited, time_counter, arrival, departure, parent);

            parent[i] = node;
        }
    }

    departure[node] = time_counter;

}

int main() {

    int n,m; cin>>n>>m;     // n=|V|, m=|E|

    vector<vector<int>> adj(n, vector<int>(0));

    int u,v;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        u--; v--;       // 0-indexing of vertices
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0);
    vector<int> arrival(n, 0);
    vector<int> departure(n, 0);
    vector<int> parent(n, 0);

    int time_counter = 0;

    for (int i=0; i<n; i++) {           // loop, in case there are more than 1 connected components
        if(!visited[i]) {
            visited[i] = 1;
            dfs(i, adj, visited, time_counter, arrival, departure, parent);
            parent[i] = -1;
        }
    }

    for (int i=0; i<n; i++) {
        cout<<i+1<<' '<<arrival[i]<<' '<<departure[i]<<' '<<parent[i]+1<<"\n";
    }

}

/*
5 5
1 2
1 4
3 5
2 5
3 2
(book graph)
*/