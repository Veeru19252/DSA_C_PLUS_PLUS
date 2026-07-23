class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        bool removed = false;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] <= prev) {
                if (removed) return false;
                removed = true;
                
                // Decide which element to remove
                if (i >= 2 && nums[i] <= nums[i - 2]) {
                    // Must remove nums[i] (current)
                    prev = nums[i - 1];
                } else {
                    // Can remove nums[i-1] (previous)
                    prev = nums[i];
                }
            } else {
                prev = nums[i];
            }
        }
        
        return true;
    }
};