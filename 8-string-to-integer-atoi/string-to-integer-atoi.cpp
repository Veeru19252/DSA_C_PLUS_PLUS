class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        long res = 0;

        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-'))
            sign = s[i++] == '-' ? -1 : 1;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return res * sign;
    }
};