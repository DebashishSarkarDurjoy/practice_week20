#include <iostream>
#include <vector>

#define inf 1000

using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph) {
    int V = graph.size();

    for (int N = 0; N < V; N++) {

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] > (graph[i][N] + graph[N][j])) {
                    graph[i][j] = graph[i][N] + graph[N][j];
                }    
            }
        }

    }

    return graph;
}


int main(void) {
    vector<vector<int>> graph = {
        {0, inf, -2, inf},
        {4, 0, 3, inf},
        {inf, inf, 0, 2},
        {inf, -1, inf, 0}
    };

    vector<vector<int>> result = floyd_warshall(graph);

    for (auto row: result) {
        for (auto data: row) {
            if (data == inf) cout << 0 << "  ";
            else cout << data << "  ";
        }
        cout << endl;
    }


    return 0;
}