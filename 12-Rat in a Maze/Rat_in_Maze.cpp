#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool **vis;
int r, c;
stack<char> s;

bool solve(bool **maze, int y, int x) {

    if (x > c-1 || y > r-1 || vis[y][x] || maze[y][x]) {
        return false;
    } else if ((x == c - 1 || y == r - 1) && maze[y][x] == 0) {
        return true;
    }

    vis[y][x] = 1;
    s.push('R');
    bool right = solve(maze, y, x+1);
    if (!right) s.pop();

    s.push('L');
    bool left = solve(maze, y, x-1);
    if (!left) s.pop();

    s.push('U');
    bool up = solve(maze, y-1, x);
    if (!up) s.pop();

    s.push('D');
    bool down = solve(maze, y+1, x);
    if (!down) s.pop();


    return (right || left || up || down);
}

int main() {
    cout << "Enter Maze Dimension:\n";
    cin >> r >> c;
    int x, y;

    bool **maze = new bool *[r];
    vis = new bool *[r];
    for (int i = 0; i < r; ++i) {
        maze[i] = new bool[r];
        vis[i] = new bool[r];
    }
    cout << "Fill the maze (0/1)\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> maze[i][j];
            vis[i][j] = 0;
        }
    }
    cout << "Starting point co-ordinates in the maze:\n";
    cin >> y  >> x;
    bool path = solve(maze, y - 1, x - 1);
    if (path) {
        vector<char> ans;
        cout << "Path found!\n";
        while (s.size() != 0) {
            ans.push_back(s.top());
            s.pop();
        }
        for (int i=ans.size()-1;i>=0;--i) {
            cout<<ans[i]<<" ";
        }
    } else cout << "Cannot Solve.";


    return 0;
}