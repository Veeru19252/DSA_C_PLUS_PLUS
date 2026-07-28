class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[idx]!=nums[i]){
                idx++;
                swap(nums[idx],nums[i]);
            }
        }
        idx++;
        return idx;
    }
};