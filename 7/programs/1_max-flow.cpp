#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& adj, vector<vector<int>>& mat, vector<int>& parents) {

    int n = (adj.size()-2)/2;

    vector<bool> visited(2*n+2, 0);        // 0 is source, 2*n+1 is sink

    fill(parents.begin(), parents.end(), -2);

    queue<int> q;
    q.push(0);      // source
    visited[0]=1;
    parents[0]=-1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(x == 2*n+1) return true;       // reached sink
        for(int i: adj[x]) {
            if(!visited[i] && mat[x][i]>0) {       // !visited, and > 0 residual capacity
                visited[i]=1;
                parents[i]=x;
                q.push(i);
            }
        }
    }

    return false;       // didn't reach sink; no augmenting path with > 0 capacity
}


int ford_fulkerson_BFS(vector<vector<int>>& adj, vector<vector<int>>& mat) {

    int n = (mat.size()-2)/2;

    vector<int> parents(2*n+2);
    
    int max_flow = 0;

    while(bfs(adj, mat, parents)) {       // while there's an augmenting path

        int x = 2*n+1;
        int currCapacity = 1e8;
    
        while(parents[x]!=-1) {
            currCapacity = min(currCapacity, mat[parents[x]][x]);
            x = parents[x];
        }
    
        x = 2*n+1;
        while(parents[x]!=-1) {
            // modify residual capacities
            mat[parents[x]][x] -= currCapacity;
            mat[x][parents[x]] += currCapacity;
            x = parents[x];
        }
    
        max_flow += currCapacity;
    
    }

    return max_flow;

}

int main() {

    int n; cin >> n;

    vector<vector<int>> adj(2*n+2,vector<int>(0));           // adj list for fast bfs
    vector<vector<int>> mat(2*n+2,vector<int>(2*n+2,0));     // matrix with residual capacities, for fast mat[][] access

    // 2*n for bipartite
    // +2 for source, sink

    // source, sink
    for(int i=1; i<=n; i++) {
        mat[0][i]=1;
        mat[i][0]=0;        // reverse edge with 0 initial capacity
        adj[0].push_back(i);
        adj[i].push_back(0);

        mat[i+n][2*n+1]=1;
        mat[2*n+1][i+n]=0;
        adj[i+n].push_back(2*n+1);
        adj[2*n+1].push_back(i+n);
    }

    // create rest of residual network using bipartite graph edges

    // cout << ford_fulkerson_BFS(adj, mat) << '\n';
}