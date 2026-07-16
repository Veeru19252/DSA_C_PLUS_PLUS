class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int x : nums) maxOR |= x;
        int count = 0;
        dfs(nums, 0, 0, maxOR, count);
        return count;
    }
    
    void dfs(vector<int>& nums, int i, int cur, int mx, int& cnt) {
        if (i == nums.size()) {
            if (cur == mx) cnt++;
            return;
        }
        dfs(nums, i + 1, cur, mx, cnt);
        dfs(nums, i + 1, cur | nums[i], mx, cnt);
    }
};