class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> cnt(2 * n + 3), pref(2 * n + 3);
        int offset = n + 1;
        pref[offset] = cnt[offset] = 1;
        long long ans = 0;
        int curr = offset;
        for (int x : nums) {
            curr += (x == target) ? 1 : -1;
            ++cnt[curr];
            pref[curr] = pref[curr - 1] + cnt[curr];
            ans += pref[curr - 1];
        }
        return ans;
    }
};