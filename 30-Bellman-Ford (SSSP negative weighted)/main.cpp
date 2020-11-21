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
int parent[N];
int dist[N];

void bellmanFord(int start, int n) {
    for (int i = 1; i <= n; ++i) dist[i] = INF; // set all nodes as unreachable
    dist[start] = 0; // distance from start to itself

    for (int i = 0; i < n - 1; ++i) { // repeat n-1 times to get correct shortest path of length n-1
        for (int j = 1; j <= n; ++j) { // for each node
            int edges = adj[j].size();
            for (int k = 0; k < edges; ++k) { // relax each edge
                ii u = adj[j][k];
                if (dist[u.f] >
                    dist[j] + u.s) { // if the distance from U to V is shorter than the current distance to V
                    dist[u.f] = dist[j] + u.s; // assign the shorter distance
                    parent[u.f] = j; // set the shortest path parent of V to U
                }
            }
        }
    }
    bool negativeCycle = false;
    // one more iteration to check if there is a negative cycle
    for (int j = 1; j <= n; ++j) {
        int edges = adj[j].size();
        for (int k = 0; k < edges; ++k) {
            ii u = adj[j][k];
            if (dist[u.f] > dist[j] + u.s) {
                negativeCycle = true;
            }
        }
    }
    if (negativeCycle) cout << "The graph has a negative cycle.\n";

    for (int i = 1; i <= n; i++) // print the shortest distance of each node from the source
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
        adj[u].push_back({v, w});
    }
    int source = 1;
    bellmanFord(source, nodes);
}
