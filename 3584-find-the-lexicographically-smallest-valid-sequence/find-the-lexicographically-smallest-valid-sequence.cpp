class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        const int n = (int)word1.size();
        const int m = (int)word2.size();

        // ---- prevDiff[i] = largest j < i with word1[j] != word1[i]  (O(n), top-2 trick) ----
        vector<int> prevDiff(n, -1);
        {
            int bestChar = -1, bestVal = -1, secondVal = -1; // max & 2nd-max of lastPos
            for (int i = 0; i < n; ++i) {
                int c = word1[i] - 'a';
                prevDiff[i] = (bestChar != c) ? bestVal : secondVal;
                if (c == bestChar) {
                    bestVal = i;
                } else if (i >= bestVal) {
                    secondVal = bestVal;
                    bestChar = c;
                    bestVal = i;
                } else if (i >= secondVal) {
                    secondVal = i;
                }
            }
        }

        // ---- position lists of each char ----
        vector<int> pos[26];
        for (int i = 0; i < n; ++i) pos[word1[i] - 'a'].push_back(i);

        // Two independent pointers per char: th0 queries use limits th0[i+1],
        // th1 option-A queries use limits th1[i+1]. Each limit sequence is
        // non-increasing as i decreases, so each pointer only moves left: O(n) total.
        int ptr0[26], ptr1[26];
        for (int c = 0; c < 26; ++c) ptr0[c] = ptr1[c] = (int)pos[c].size() - 1;

        // th0[i] = latest start in word1 from which word2[i..] is an exact subsequence
        // th1[i] = latest start in word1 from which word2[i..] matches with <= 1 mismatch
        vector<int> th0(m + 1), th1(m + 1);
        th0[m] = n;
        th1[m] = n;
        for (int i = m - 1; i >= 0; --i) {
            int c = word2[i] - 'a';
            int L1 = th1[i + 1];               // option A: match this char, rest uses <=1 mismatch
            while (ptr1[c] >= 0 && pos[c][ptr1[c]] >= L1) --ptr1[c];
            int predA = (ptr1[c] >= 0) ? pos[c][ptr1[c]] : -1;

            int L0 = th0[i + 1];               // th0 + option B: burn the mismatch here, rest exact
            while (ptr0[c] >= 0 && pos[c][ptr0[c]] >= L0) --ptr0[c];
            int predB = (ptr0[c] >= 0) ? pos[c][ptr0[c]] : -1;

            th0[i] = predB;
            int optMismatch = (L0 > 0) ? ((word1[L0 - 1] - 'a' != c) ? (L0 - 1) : prevDiff[L0 - 1]) : -1;
            th1[i] = max(predA, optMismatch);
        }

        // ---- greedy: earliest feasible index per step ----
        vector<int> ans;
        int used = 0;       // mismatches already consumed (0 or 1)
        int prev = -1;      // last chosen index
        for (int t = 0; t < m; ++t) {
            int c = word2[t] - 'a';
            int limitMatch    = (used == 0) ? th1[t + 1] : th0[t + 1];
            int limitMismatch = (used == 0) ? th0[t + 1] : -1;
            int hardLimit = max(limitMatch, limitMismatch);

            int chosen = -1;
            for (int p = prev + 1; p < n && p < hardLimit; ++p) {
                bool ok;
                if (word1[p] - 'a' == c)
                    ok = (p < limitMatch);
                else
                    ok = (used == 0 && p < limitMismatch);
                if (ok) { chosen = p; break; }
            }
            if (chosen == -1) return {};

            ans.push_back(chosen);
            if (word1[chosen] - 'a' != c) used = 1;
            prev = chosen;
        }
        return ans;
    }
};