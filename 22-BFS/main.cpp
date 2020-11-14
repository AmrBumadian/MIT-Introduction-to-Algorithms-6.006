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

int bfs(int n) { // bfs and count components
    int cnt = 0;
    for (int i = 1; i <= n; ++i) { // start traversing once from each node
        if (!vis[i]) { // if the node is visited already skip this path
            ++cnt; // increment components number
            queue<int> q;
            q.push(i); // push current node to the queue
            vis[i] = true;
            while (!q.empty()) { // while there is no more nodes to traverse through
                int temp = q.front();
                q.pop(); // dequeue the front node and print it
                int neighbours = adj[temp].size();
                cout << temp << " ";
                for (int j = 0; j < neighbours; ++j) { // traverse all its neighbours
                    int node = adj[temp][j];
                    if (!vis[node]) {
                        q.push(node);
                        vis[node] = true;
                    }
                }
            }
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
    cout << bfs(nodes);
}
