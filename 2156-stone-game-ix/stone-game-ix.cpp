class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        for (int s : stones) ++cnt[s % 3];

        int c0 = cnt[0], c1 = cnt[1], c2 = cnt[2];

        if (c0 % 2 == 0)                     // even number of neutral (mod 3 == 0) stones
            return c1 > 0 && c2 > 0;         // Alice wins iff both residue-1 and residue-2 exist
        return abs(c1 - c2) > 2;             // odd neutral stones: Alice wins iff imbalance > 2
    }
};