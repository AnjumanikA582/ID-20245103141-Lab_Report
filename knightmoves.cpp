#include <iostream>
using namespace std;

int main() {
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

    string start, end;
    while (cin >> start >> end) {
        // convert column letter to number (a=0, h=7)
        int x1 = start[0] - 'a';
        int y1 = start[1] - '1';
        int x2 = end[0] - 'a';
        int y2 = end[1] - '1';
        int dist[8][8];
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                dist[i][j] = -1;
        int qx[64], qy[64];
        int front = 0, back = 0;
        qx[back] = x1;
        qy[back] = y1;
        back++;
        dist[x1][y1] = 0;

        while (front < back) {
            int cx = qx[front];
            int cy = qy[front];
            front++;
            for (int k = 0; k < 8; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    qx[back] = nx;
                    qy[back] = ny;
                    back++;
                }
            }
        }

        cout << "To get from " << start << " to " << end
             << " takes " << dist[x2][y2] << " knight moves.\n";
    }

    return 0;
}
