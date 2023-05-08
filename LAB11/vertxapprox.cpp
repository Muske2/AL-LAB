#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> vertex_cover(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> cover;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            for (int j = 0; j < graph[i].size(); ++j) {
                int neighbor = graph[i][j];
                if (!visited[neighbor]) {
                    visited[i] = true;
                    visited[neighbor] = true;
                    cover.push_back(i);
                    cover.push_back(neighbor);
                    break;
                }
            }
        }
    }
    return cover;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> cover = vertex_cover(graph);
    cout << "Minimum Vertex Cover Size: " << cover.size() << endl;
    cout << "Vertex Cover: ";
    for (int i = 0; i < cover.size(); ++i) {
        cout << cover[i] << " ";
    }
    cout << endl;
    return 0;
}


