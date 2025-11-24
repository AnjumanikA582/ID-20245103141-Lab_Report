#include <iostream>
using namespace std;

const long long INF = 1e18;
const int MAXN = 5005;
const int MAXE = 200005;

int first[MAXN], nextEdge[MAXE*2], endPoint[MAXE*2];
long long weight[MAXE*2];
int edgeNum;

void addRoad(int a, int b, long long c) {
    edgeNum++;
    endPoint[edgeNum] = b;
    weight[edgeNum] = c;
    nextEdge[edgeNum] = first[a];
    first[a] = edgeNum;
}

int main() {
    int test;
    cin >> test;

    for (int t = 1; t <= test; t++) {
        int n, r;
        cin >> n >> r;

        for (int i = 1; i <= n; i++) first[i] = 0;
        edgeNum = 0;

        for (int i = 0; i < r; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            addRoad(u, v, w);
            addRoad(v, u, w);
        }

        long long d1[MAXN], d2[MAXN];
        bool vis[MAXN];

        for (int i = 1; i <= n; i++) {
            d1[i] = INF;
            d2[i] = INF;
            vis[i] = false;
        }

        d1[1] = 0;

        for (int i = 1; i <= n; i++) {
            int cur = -1;
            long long minD = INF;

            for (int j = 1; j <= n; j++) {
                if (!vis[j] && d1[j] < minD) {
                    minD = d1[j];
                    cur = j;
                }
            }

            if (cur == -1) break;
            vis[cur] = true;

            for (int e = first[cur]; e != 0; e = nextEdge[e]) {
                int v = endPoint[e];
                long long newD = d1[cur] + weight[e];

                if (newD < d1[v]) {
                    d2[v] = d1[v];
                    d1[v] = newD;
                } else if (newD > d1[v] && newD < d2[v]) {
                    d2[v] = newD;
                }

                newD = d2[cur] + weight[e];
                if (newD > d1[v] && newD < d2[v]) d2[v] = newD;
            }
        }

        cout << "Case " << t << ": " << d2[n] << "\n";
    }

    return 0;
}

