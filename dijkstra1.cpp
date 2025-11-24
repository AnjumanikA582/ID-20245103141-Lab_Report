#include <iostream>
using namespace std;

const long long INF = 1e18;
const int MAXN = 100005;
const int MAXM = 200005; 
int head[MAXN], nxt[MAXM], to[MAXM];
long long w[MAXM];
int edge_count = 0;

void add_edge(int u, int v, long long weight) {
    edge_count++;
    to[edge_count] = v;
    w[edge_count] = weight;
    nxt[edge_count] = head[u];
    head[u] = edge_count;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) head[i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long weight;
        cin >> a >> b >> weight;
        add_edge(a, b, weight);
        add_edge(b, a, weight);
    }

    long long dist[MAXN];
    int parent[MAXN];
    bool visited[MAXN];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }

    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1;
        long long min_dist = INF;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        if (u == -1) break; 
        visited[u] = true;
        for (int e = head[u]; e != 0; e = nxt[e]) {
            int v = to[e];
            if (dist[u] + w[e] < dist[v]) {
                dist[v] = dist[u] + w[e];
                parent[v] = u;
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << "\n";
    } else {
        int path[MAXN];
        int path_len = 0;
        int cur = n;
        while (cur != -1) {
            path[path_len++] = cur;
            cur = parent[cur];
        }
        for (int i = path_len - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
