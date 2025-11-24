#include <iostream>
using namespace std;

#define INF 1000000000
#define MAXN 201

int n;
int busyness[MAXN];
int dist[MAXN];
int r;

struct Road {
    int u, v;
    int cost;
} roads[MAXN * MAXN];

int main() {
    int setNumber = 1;

    while (cin >> n) {
        if (n == 0) break;

        for (int i = 1; i <= n; i++) {
            cin >> busyness[i];
        }

        cin >> r;

        for (int i = 0; i < r; i++) {
            int u, v;
            cin >> u >> v;
            roads[i].u = u;
            roads[i].v = v;
            int diff = busyness[v] - busyness[u];
            roads[i].cost = diff * diff * diff;
        }

        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
        }
        dist[1] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < r; j++) {
                int u = roads[j].u;
                int v = roads[j].v;
                int cost = roads[j].cost;
                if (dist[u] != INF && dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                }
            }
        }

        int q;
        cin >> q;

        cout << "Set #" << setNumber << "\n";
        for (int i = 0; i < q; i++) {
            int dest;
            cin >> dest;
            if (dist[dest] < 3 || dist[dest] == INF) {
                cout << "?\n";
            } else {
                cout << dist[dest] << "\n";
            }
        }

        setNumber++;
    }

    return 0;
}
