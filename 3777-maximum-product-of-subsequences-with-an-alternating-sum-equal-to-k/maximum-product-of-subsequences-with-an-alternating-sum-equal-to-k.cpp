class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (k > total || k < -total) return -1;

        unordered_map<int, unordered_set<int>> dp[2];

        for (int x : nums) {
            unordered_map<int, unordered_set<int>> add[2];

            add[1][x].insert(x);

            for (int p : {0, 1}) {
                for (const auto& [s, prods] : dp[p]) {
                    int ns = s + (p == 0 ? x : -x);
                    for (int v : prods) {
                        long long np = 1LL * v * x;
                        add[p ^ 1][ns].insert(np > limit ? limit + 1 : (int)np);
                    }
                }
            }

            for (int p : {0, 1})
                for (auto& [s, prods] : add[p])
                    for (int v : prods)
                        dp[p][s].insert(v);
        }

        int ans = -1;
        for (int p : {0, 1}) {
            auto it = dp[p].find(k);
            if (it == dp[p].end()) continue;
            for (int v : it->second)
                if (v <= limit) ans = max(ans, v);
        }
        return ans;
    }
};