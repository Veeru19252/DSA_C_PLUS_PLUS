class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int freq[26] = {};
        for (char c : s) ++freq[c - 'a'];

        int half[26] = {};
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1) mid = 'a' + i;
        }

        int halfLen = s.size() / 2;
        if (countPerms(half, k) < k) return "";

        string left;
        for (int pos = 0; pos < halfLen; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (half[i] == 0) continue;
                --half[i];
                long long cnt = countPerms(half, k);
                if (cnt >= k) {
                    left.push_back('a' + i);
                    break;
                }
                k -= cnt;
                ++half[i];
            }
        }

        string right(left.rbegin(), left.rend());
        return left + (mid ? string(1, mid) : "") + right;
    }

private:
    long long binom(int n, int r, long long cap) {
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - r + i) / i;
            if (res > cap) return cap + 1;
        }
        return res;
    }

    long long countPerms(const int cnt[26], long long cap) {
        int total = 0;
        for (int i = 0; i < 26; ++i) total += cnt[i];
        long long res = 1;
        int remaining = total;
        for (int i = 0; i < 26; ++i) {
            int c = cnt[i];
            if (c == 0) continue;
            long long cb = binom(remaining, c, cap);
            if (cb > cap) return cap + 1;
            res *= cb;
            if (res > cap) return cap + 1;
            remaining -= c;
        }
        return res;
    }
};