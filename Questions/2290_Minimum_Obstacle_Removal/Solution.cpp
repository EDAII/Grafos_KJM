#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e5));
        deque<pair<int,int>> dq;

        dist[0][0] = 0;
        dq.emplace_back(0,0);

        const int dx[4] = {1,-1,0,0};
        const int dy[4] = {0,0,1,-1};

        while (!dq.empty()) {
            auto [x,y] = dq.front();
            dq.pop_front();
            int d = dist[x][y];

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int w = grid[nx][ny];

                int nd = d + w;
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    if (w == 0) dq.emplace_front(nx, ny);
                    else        dq.emplace_back(nx, ny);
                }
            }
        }
        return dist[n-1][m-1];
    }
};