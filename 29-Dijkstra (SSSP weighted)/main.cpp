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


void dijkstra(int start, int n) {
    for (int i = 1; i <= n; ++i) dist[i] = INF; // set all nodes as unreachable
    dist[start] = 0; // distance from start to itself
    priority_queue<ii, vii, greater<ii>> frontier; // to get the shortest distance node at log(n) per extraction
    frontier.push(ii(0, start)); // add the start to the queue

    while (!frontier.empty()) {
        ii front = frontier.top(); // extract the frontier top then remove it
        frontier.pop();
        int d = front.f; // current shortest distance to this node
        int u = front.s; // the node number
        if (d > dist[u]) continue; // skip if already found another path that is shorter
        int edges = adj[u].size(); // edges going out of this node
        for (int j = 0; j < edges; ++j) { // relax all edges
            ii v = adj[u][j]; // edge between U and V
            if (dist[u] + v.s < dist[v.f]) { // if the distance from U to V is shorter than the current distance to V
                dist[v.f] = dist[u] + v.s; // assign the shorter distance
                frontier.push(ii(dist[v.f], v.f)); // add it to the frontier
                parent[v.f] = u; // set the shortest path parent of V to U
            }
        }
    }
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
    dijkstra(source, nodes);
    int current = 9;

    cout << current << " ";
    while (current != source) { // print the path from current to source
        cout << parent[current] << " ";
        current = parent[current];
    }
}
