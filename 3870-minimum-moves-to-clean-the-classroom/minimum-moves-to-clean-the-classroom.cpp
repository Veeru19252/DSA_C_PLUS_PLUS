class Solution {
public:
    int minMoves(vector<string>& classroom, int energyCap) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int,int>> litter;              // L cell positions
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                char ch = classroom[r][c];
                if (ch == 'S') { sr = r; sc = c; }
                else if (ch == 'L') {
                    litterId[r][c] = litter.size();
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();
        if (k == 0) return 0;                       // nothing to collect

        int fullMask = (1 << k) - 1;
        int E = energyCap;                           // energy levels: 0..E
        int maskCnt = 1 << k;

        // flattened index: ((r*n + c) * maskCnt + mask) * (E+1) + e
        auto idx = [&](int r, int c, int mask, int e) {
            return ((r * n + c) * maskCnt + mask) * (E + 1) + e;
        };

        long long totalStates = (long long)m * n * maskCnt * (E + 1);
        vector<bool> visited(totalStates, false);

        queue<tuple<int,int,int,int,int>> q;  // r, c, mask, e, moves
        int startMask = 0; // S itself is never 'L'
        visited[idx(sr, sc, startMask, E)] = true;
        q.push({sr, sc, startMask, E, 0});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, mask, e, moves] = q.front();
            q.pop();

            if (mask == fullMask) return moves;   // BFS => first hit is minimal

            if (e == 0) continue;                 // stuck, no move possible

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                char ch = classroom[nr][nc];
                if (ch == 'X') continue;

                int ne = e - 1;
                if (ch == 'R') ne = E;             // reset to MAX, not add

                int nmask = mask;
                if (ch == 'L' && !(mask & (1 << litterId[nr][nc])))
                    nmask |= (1 << litterId[nr][nc]);

                int id = idx(nr, nc, nmask, ne);
                if (!visited[id]) {
                    visited[id] = true;
                    q.push({nr, nc, nmask, ne, moves + 1});
                }
            }
        }

        return -1;   // fullMask never reached
    }
};