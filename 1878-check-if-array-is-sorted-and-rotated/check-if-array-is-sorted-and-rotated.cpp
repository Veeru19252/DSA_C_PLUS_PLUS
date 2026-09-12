class Solution {
public:
    bool check(vector<int>& nums) {
        int peak_ele=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()])peak_ele++;
        }
        return peak_ele<=1;
    }
};