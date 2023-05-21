#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m; cin>>n>>m;     // n=|V|, m=|E|

    vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>(0));       // adj list
    vector<int> dist;        // final distances from source
    vector<bool> processed;

    int src; cin>>src;      // source
    src--;                  // 0-indexing of vertices

    int u, v, w;        // u-v with weight w
    for (int i=0; i<m; i++) {
        cin>>u>>v>>w;
        u--; v--;           // 0-indexing
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> q;        // min priority queue
    // will compare the first elements of the pairs
    // greater<>, to get min. element at top

    // (another way is to use default p_q and distances with a negative sign)

    // pairs of the form (d, x), meaning that the current distance from source to node `x` is `d`

    dist.resize(n, INT_MAX/2);      // initial distances: INF
    processed.resize(n, false);

    dist[src] = 0;
    q.push({dist[src], src});

    while(!q.empty()) {                     // repeat until all nodes get processed
        int x = q.top().second;     // unprocessed node that has minimum dist currently
        q.pop();

        if(processed[x]) continue;
        
        processed[x]=true;

        for (auto i:adj[x]) {
            v = i.first;
            w = i.second;
            if (dist[x]+w < dist[v]) {      // this won't be true for any 'processed' nodes
                                            // this can be seen in correctness proof of Dijkstra
                                            // so checking !processed[i] is redundant
                dist[v] = dist[x]+w;
                q.push({dist[v],v});

                // note: we might be pushing this v multiple times throughout the run
                // however, each instance of v would have a different pair.first value (i.e. distance)
                // since the latest dist[v] would be smallest, so priority_queue will process this instance 
                // sooner than any other instance of v.
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout<<i+1<<' '<<dist[i]<<"\n";
    }

/*
5 6 1
2 3 2
3 4 6
2 1 5
1 4 9
1 5 1
4 5 2
(same as in doc)
*/

}