class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        auto count = [&](long long x) -> long long {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                bool skip = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        l = lcm(l, (long long)coins[i]);
                        if (l > x) { skip = true; break; }   // x/l would be 0
                    }
                }
                if (skip) continue;
                if (__builtin_popcount(mask) & 1) total += x / l;
                else                              total -= x / l;
            }
            return total;
        };
        
        long long lo = 1, hi = (long long)k * *min_element(coins.begin(), coins.end());
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k) hi = mid;
            else                 lo = mid + 1;
        }
        return lo;
    }
};