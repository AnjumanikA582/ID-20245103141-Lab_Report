#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0) 
            break;

        int l;
        cin >> l;
        static int graph[200][200];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = 0;
        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        int color[200];
        for (int i = 0; i < n; i++)
            color[i] = -1;
        int q[200];
        int front = 0, back = 0;
        color[0] = 0;
        q[back++] = 0;

        bool ok = true;

        while (front < back && ok) {
            int node = q[front++];
            
            for (int i = 0; i < n; i++) {
                if (graph[node][i] == 1) {  
                    if (color[i] == -1) {
                        // give opposite color
                        color[i] = 1 - color[node];
                        q[back++] = i;
                    }
                    else if (color[i] == color[node]) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (ok)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
