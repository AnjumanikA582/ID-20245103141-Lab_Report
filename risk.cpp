#include <iostream>
using namespace std;

int main() {
    int T = 1;

    while (true) {
        int x;
        int g[21][21] = {0};
        if (!(cin >> x)) break;
        int count = x;
        int a, b;
        for (int i = 1; i <= 19; i++) {
            if (i != 1) cin >> count;

            for (int k = 0; k < count; k++) {
                cin >> b;
                g[i][b] = 1;
                g[b][i] = 1;
            }
        }

        int N;
        cin >> N;

        cout << "Test Set #" << T << "\n";

        while (N--) {
            cin >> a >> b;
            int dist[21];
            for (int i = 1; i <= 20; i++) dist[i] = -1;

            int q[21];
            int front = 0, back = 0;

            dist[a] = 0;
            q[back++] = a;

            while (front < back) {
                int u = q[front++];
                for (int v = 1; v <= 20; v++) {
                    if (g[u][v] && dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q[back++] = v;
                    }
                }
            }

            cout.width(2);
            cout << a;
            cout << " to ";
            cout.width(2);
            cout << b;
            cout << ": " << dist[b] << "\n";
        }

        cout << "\n";
        T++;
    }

    return 0;
}
