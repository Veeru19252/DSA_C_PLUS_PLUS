class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int max_ele=max(nums[0]*nums[1]*nums[2],nums[n]*nums[n-1]*nums[n-2]);
        return max(max_ele,nums[0]*nums[1]*nums[n]);

    }
};