class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        static int f[500][500], maxl[500][500], maxr[500][500];
        // zero out only the region we use
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) f[i][j] = maxl[i][j] = maxr[i][j] = 0;

        for (int left = n - 1; left >= 0; --left) {
            maxl[left][left] = maxr[left][left] = stoneValue[left];
            int sum = stoneValue[left], suml = 0, i = left - 1;
            for (int right = left + 1; right < n; ++right) {
                sum += stoneValue[right];
                while (i + 1 < right && (suml + stoneValue[i + 1]) * 2 <= sum)
                    suml += stoneValue[++i];

                int best = 0;
                if (left <= i) best = maxl[left][i];
                if (i + 1 < right) best = max(best, maxr[i + 2][right]);
                if (suml * 2 == sum) best = max(best, maxr[i + 1][right]);
                f[left][right] = best;

                maxl[left][right] = max(maxl[left][right - 1], sum + best);
                maxr[left][right] = max(maxr[left + 1][right], sum + best);
            }
        }
        return f[0][n - 1];
    }
};