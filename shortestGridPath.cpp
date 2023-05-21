#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Node {
public:
    int x, y;
    int dist;

    Node (int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

class Compare {
public:
    bool operator()(const Node* A, const Node* B) const {
        return A->dist <= B->dist;
    }
};

int shortestGridPath(vector<vector<int>> &grid) {
    // int min_total = 0;

    set<Node*, Compare> s;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    int m = grid.size();
    int n = grid[0].size();
    
    int i = 0;
    int j = 0;

    vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
    dist[i][j] = grid[0][0];

    Node* firstNode = new Node(0,0,dist[0][0]);
    s.insert(firstNode);
    while (!s.empty()) {
        auto it = s.begin();
        int cx = (*it)->x;
        int cy = (*it)->y;
        int c_dist = (*it)->dist;
        s.erase(it);

        for (int k = 0; k < 4; k++) {
            int nx = dx[k] + cx;
            int ny = dy[k] + cy;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && c_dist + grid[nx][ny]  < dist[nx][ny]) {
                Node* temp = new Node(ny, ny, dist[nx][ny]);
                if (s.find(temp) != s.end()) {
                    s.erase(temp);
                }
                
                int new_dist = c_dist + grid[nx][ny];
                dist[nx][ny] = new_dist;
                s.insert(new Node(nx, ny, new_dist));
            }
        }

    }

    for (auto row: dist) {
        for (auto data: row) cout << data << " ";
        cout << endl;
    }

    return dist[m-1][n-1];
}

int main(void) {
    vector<vector<int>> grid = {
        {31, 100, 64, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20}
    };

    // for (auto row: grid) {
    //     for (auto data: row) cout << data << " ";
    //     cout << endl;
    // }

    int shortest_path = shortestGridPath(grid);

    cout << shortest_path << endl;

    return 0;
}