#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;    // |V|
    // nodes numbered 0...(n-1)

    int m; cin >> m;    // |E|

    /*Adjacency list*/

    vector<vector<int>> adjacency_list(n, vector<int>(0));
    
    int u, v;
    for (int i=0; i<m; i++) {
        cin >> u >> v;
        adjacency_list[u].push_back(v);
        // adjacency_list[v].push_back(u);  // for undirected graphs
    }

    cout << "Adjacency list:\t";
    for (int i=0; i<(int)adjacency_list.size(); i++) {
        for (auto j : adjacency_list[i]) {
            cout << i << "->" << j << "\t";
        }
    }

    /*Adjacency matrix*/

    vector<vector<int>> adjacency_matrix(n, vector<int>(n, 0));

    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adjacency_matrix[u][v] = 1;
        // adjacency_matrix[v][u] = 1;      // undirected
    }

    /*Edge list*/

    vector<pair<int,int>> edge_list(m);

    for(int i=0; i<m; i++) {
        cin >> u >> v;
        edge_list.push_back({u,v});
    }

    /*Weighted graph
        Edge of the form (u,v) with weight w

        vector<vector<pair<int,int>>> adjacency_list;
            adjacency_list[u].push_back({v,w});
        
        vector<vector<int>> adjacency_matrix(n, vector<int>(n, 0));
            adjacency_matrix[u][v] = w;
        
        vector<pair<pair<int,int>,int>> edge_list;
            edge_list.insert({{u,v},w});
    */

}

/*
input:
6 7
0 1
0 4
1 2
4 3
5 0
3 2
5 1
*/