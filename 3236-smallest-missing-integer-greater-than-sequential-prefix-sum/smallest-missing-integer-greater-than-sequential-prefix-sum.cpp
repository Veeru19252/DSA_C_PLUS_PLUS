class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());

        int sum = nums[0];                          // sum of the longest sequential prefix
        for (int i = 1; i < (int)nums.size() && nums[i] == nums[i - 1] + 1; ++i)
            sum += nums[i];

        while (present.count(sum)) ++sum;           // smallest missing value >= sum
        return sum;
    }
};