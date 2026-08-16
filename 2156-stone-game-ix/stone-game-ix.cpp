class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int x : stones) ++cnt[x % 3];

        // Stones with remainder 0 never change the running sum mod 3,
        // so they act as "free passes". Their parity decides the outcome.
        if (cnt[0] % 2 == 0) {
            // Even passes: Alice wins iff BOTH remainder-1 and remainder-2
            // stones exist (otherwise she is forced to make sum % 3 == 0).
            return cnt[1] != 0 && cnt[2] != 0;
        }
        // Odd passes flip parity: Alice wins iff the two non-zero classes
        // differ by at least 3.
        return abs(cnt[1] - cnt[2]) >= 3;
    }
};