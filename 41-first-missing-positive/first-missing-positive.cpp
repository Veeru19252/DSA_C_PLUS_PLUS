class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int smallest_ele=1;
        for(int i=0;i<nums.size();i++){
            if(smallest_ele==nums[i])smallest_ele++;
        }
        return smallest_ele;

    }
};