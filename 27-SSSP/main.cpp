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
vector<vi> adj; // adjacency list
bool vis[N]; // flag the node as visited to avoid looping
int parent[N]; // store the node's parent
int dist[N]; // store the node's distance from source

void bfs(int start) { // bfs and count components

    queue<int> q;
    q.push(start); // push current node to the queue
    vis[start] = true;
    dist[start] = 0;
    while (!q.empty()) { // while there is no more nodes to traverse through
        int previous = q.front();
        q.pop(); // dequeue the front node and print it
        int neighbours = adj[previous].size();
        cout << previous << " ";
        for (int j = 0; j < neighbours; ++j) { // traverse all its neighbours
            int node = adj[previous][j];
            if (!vis[node]) {
                parent[node] = previous; // assign previous node as current's parent
                dist[node] = dist[previous] + 1;
                q.push(node);
                vis[node] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    memset(parent, -1, sizeof(parent)); // initially all nodes have no parent
    int nodes, edges, u, v;
    cin >> nodes >> edges; // number of nodes
    adj.resize(nodes + 1); // adjacency list
    for (int i = 0; i < edges; ++i) {
        cin >> v >> u; // vertex and edge
        adj[v].push_back(u); // directed
        adj[u].push_back(v); // add if undirected
    }
    int start, destination;
    cin >> start >> destination;
    cout << "BFS Traversal: ";
    bfs(start);

    cout << dist[destination] << "\n";
    cout << "The path reversed is: ";
    int to = destination;

    int edge = 0;
    while (to != -1) { // while current node has a parent print that parent
        if (edge) cout << "->";
        cout << to;
        to = parent[to];
        ++edge;
    }
    return 0;
}
