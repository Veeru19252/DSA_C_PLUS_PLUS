class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> prev(n + 1, false), curr(n + 1, false);
        
        prev[0] = true;
        for (int j = 1; j <= n; j++)
            if (p[j - 1] == '*' && j >= 2)
                prev[j] = prev[j - 2];
        
        for (int i = 1; i <= m; i++) {
            curr[0] = false;
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    curr[j] = prev[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    curr[j] = curr[j - 2];
                    if (p[j - 2] == '.' || s[i - 1] == p[j - 2])
                        curr[j] = curr[j] || prev[j];
                }
            }
            swap(prev, curr);
        }
        
        return prev[n];
    }
};