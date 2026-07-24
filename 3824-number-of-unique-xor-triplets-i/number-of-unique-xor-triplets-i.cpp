class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        // Base cases: n < 3
        if (n < 3) return n;
        
        // For n >= 3: all values [0, 2^m - 1] are achievable
        // where m = floor(log2(n)) + 1
        int msb = 31 - __builtin_clz(n);  // floor(log2(n))
        return 1 << (msb + 1);             // 2^(msb+1)
    }
};