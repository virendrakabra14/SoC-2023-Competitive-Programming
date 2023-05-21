#include <bits/stdc++.h>
using namespace std;

bool topoSort(int i, vector<vector<int>>& adj, vector<int>& sorting, vector<int>& state) {
    // returns 0 if cycle is present

    if(state[i]==1) {       // reach a node "in processing" => (directed) cycle present
        return 0;
    }
    else if(state[i]==0) {
        state[i] = 1;       // mark as "in processing"
        for (auto j:adj[i]) {
            if(!topoSort(j, adj, sorting, state)) {
                return 0;
            }
        }
        state[i] = 2;       // processing complete
        sorting.push_back(i);       // push back after processing children,
                                    // and reverse `sorting` at the end (see main)
    }
    return 1;
}

int main() {
    
    int n,m; cin>>n>>m;     // n=|V|, m=|E|

    vector<vector<int>> adj(n, vector<int>(0));
    
    int u,v;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);       // DAG: directed
    }

    vector<int> state(n, 0);
    vector<int> sorting(0);

    for (int i=0; i<n; i++) {
        if(state[i] == 0) {         // didn't start processing
            if(!topoSort(i, adj, sorting, state)) {
                cout << "cycle\n";
                return 0;
            }
        }
    }
    reverse(sorting.begin(), sorting.end());        // e.g., 1->2->3->4, and start at 2
    
    for (int i=0; i<n; i++) {
        cout << sorting[i] + 1 << ' ';
    }

}

/*
6 7
1 2
4 1
4 5
5 2
2 3
5 3
3 6
---
(cycle)
6 7
4 1
4 5
1 2
5 2
2 3
3 5
3 6
---
(book diagrams)
*/