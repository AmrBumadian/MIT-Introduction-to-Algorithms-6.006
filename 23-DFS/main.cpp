#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> mpsi;
typedef map<int, int> mpii;

inline void BOOST() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
}

const int N = 2 * (1e5 + 1);
vector<vi> adj;
bool vis[N];

void dfs(int v) { // dfs the path starting at v

    cout << v << " ";
    int neighbours = adj[v].size();
    for (int i = 0; i < neighbours; ++i) { // traverse all the neighbours of v and dfs at each one
        int node = adj[v][i];
        if (!vis[node]) {
            vis[node] = true; // mark visited to avoid loops
            dfs(node);
        }
    }
}

int dfsEveryPath(int n) { // dfs at each node if all not connected
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++cnt;
            dfs(i); // dfs at current node
            cout << endl;
        }
    }
    return cnt;
}


int main() {
    int nodes, edges, u, v;
    cin >> nodes >> edges; // number of nodes
    adj.resize(nodes + 1); // adjacency list
    for (int i = 0; i < edges; ++i) {
        cin >> v >> u; // vertex and edge
        adj[v].push_back(u); // directed
        //adj[u].push_back(v); // add if undirected
    }
    cout << dfsEveryPath(nodes);
}
