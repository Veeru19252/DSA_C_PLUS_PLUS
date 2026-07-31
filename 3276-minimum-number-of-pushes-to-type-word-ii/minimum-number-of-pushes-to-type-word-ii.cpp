class Solution {
public:
    int minimumPushes(string word) {
        // 1. Count frequency of each character
        int freq[26] = {};
        for (char c : word) ++freq[c - 'a'];

        // 2. Sort frequencies descending
        sort(freq, freq + 26, greater<int>());

        // 3. Greedy: most frequent letters get the cheapest positions
        //    i = 0..7   → 1 push each
        //    i = 8..15  → 2 pushes each
        //    i = 16..23 → 3 pushes each
        //    i = 24..25 → 4 pushes each
        int ans = 0;
        for (int i = 0; i < 26 && freq[i] > 0; ++i) {
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};