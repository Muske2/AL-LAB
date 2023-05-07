#include <iostream>
#include <vector>
using namespace std;

int N, maxCliqueSize = 0;
vector<int> clique;
int adj[100][100];

bool isClique(vector<int>& vertices) {
    for (int i = 0; i < vertices.size(); i++) {
        for (int j = i + 1; j < vertices.size(); j++) {
            if (adj[vertices[i]][vertices[j]] == 0) {
                return false;
            }
        }
    }
    return true;
}

void findMaxClique(vector<int>& vertices, int node) {
    if (node == N) {
        if (isClique(vertices)) {
            if (vertices.size() > maxCliqueSize) {
                maxCliqueSize = vertices.size();
                clique = vertices;
            }
        }
        return;
    }

    if (vertices.size() + N - node < maxCliqueSize) {
        return;
    }

    vertices.push_back(node);
    findMaxClique(vertices, node + 1);
    vertices.pop_back();

    findMaxClique(vertices, node + 1);
}

int main() {
    cout << "Number of edges: ";
    cin >> N;
     int src,dest,x;
    for(int i=0;i<N;i++)
    {
        cout<<"Enter source: "<<endl;
        cin>>src;
        cout<<"Enter destination: "<<endl;
        cin>>dest;
        adj[src][dest]=1;
        adj[dest][src]=1;
    }
    vector<int> vertices;
    findMaxClique(vertices, 0);

    cout << "Max clique size: " << maxCliqueSize << endl;
    cout << "Vertices in clique: ";
    for (int i = 0; i < clique.size(); i++) {
        cout << clique[i] << " ";
    }
    cout << endl;

    return 0;
}
