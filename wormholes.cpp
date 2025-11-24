#include <iostream>
#include <limits>

using namespace std;

struct Edge {
    int from;
    int to;
    int time;
};

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        Edge edges[2000];
        for (int i = 0; i < m; i++) {
            cin >> edges[i].from >> edges[i].to >> edges[i].time;
        }

        long long dist[1000];
        for (int i = 0; i < n; i++) dist[i] = 0;

        bool changed = false;
        for (int i = 0; i < n; i++) {
            changed = false;
            for (int j = 0; j < m; j++) {
                int u = edges[j].from;
                int v = edges[j].to;
                int w = edges[j].time;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }
            if (!changed) break;
        }

        bool possible = false;
        if (changed) {
            for (int j = 0; j < m; j++) {
                int u = edges[j].from;
                int v = edges[j].to;
                int w = edges[j].time;
                if (dist[v] > dist[u] + w) {
                    possible = true;
                    break;
                }
            }
        }

        if (possible) cout << "possible\n";
        else cout << "not possible\n";
    }
    return 0;
}
