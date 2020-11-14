#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define INF 1e9

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
vector<vii> adj;
bool vis[N];
stack<int> topo;
int dist[N];
int parent[N];

void dfs(int v) {
    vis[v] = true; // mark this node as visited
    int neighbours = adj[v].size();
    for (int i = 0; i < neighbours; ++i) { // traverse all the neighbours of v and dfs at each one
        int node = adj[v][i].f;
        if (!vis[node]) {
            dfs(node);
        }
    }
    topo.push(v); // push current node to the stack as it's not finished yet
}

void topologicalSort(int n) { // dfs at each node
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i); // dfs at current node
        }
    }
}

void shortestPath(int start, int n) {
    topologicalSort(n); // form a linear ordering of the nodes
    for (int i = 0; i <= n; ++i) dist[i] = INF; // each node is unreachable in the beginning
    dist[start] = 0; // distance from source to itself is 0

    while (!topo.empty()) {
        int v = topo.top();
        topo.pop();
        if (dist[v] != INF) { // if reachable
            int neighbours = adj[v].size();
            for (int j = 0; j < neighbours; ++j) { // relax all the edges going out of node V
                int u = adj[v][j].f, w = adj[v][j].s;
                if (dist[u] > dist[v] + w) { // if distance to U from V is less than current distance
                    dist[u] = dist[v] + w; // change the distance
                    parent[u] = v; // make V the parent of U
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) // print the distance of each node from the source
        (dist[i] == INF) ? cout << "INF " : cout << dist[i] << " ";
    cout << endl;
}


int main() {
    int nodes, edges, u, v, w;
    cin >> nodes >> edges; // number of nodes
    adj.resize(nodes + 1); // adjacency list
    for (int i = 0; i < edges; ++i) {
        cin >> v >> u >> w; // vertex and edge
        adj[v].push_back({u, w});
    }
    shortestPath(2, nodes);
}
