class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;
        for (int right = 0, left = 0; right < (int)nums.size(); ++right) {
            freq[nums[right]]++;
            while (freq[nums[right]] > k) {   // only the newly added element can exceed k
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};