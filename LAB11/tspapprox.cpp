#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m, parent[MAXN];
double ans = 0;

struct edge {
    int u, v;
    double w;
};

vector<edge> edges;

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        double w = edges[i].w;
        if (find(u) != find(v)) {
            merge(u, v);
            ans += w;
        }
    }

    cout << "The minimum cost of the TSP is " << ans << endl;

    return 0;
}

