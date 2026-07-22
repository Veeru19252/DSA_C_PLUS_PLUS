class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){swap(nums[idx],nums[i]);idx++;}
        }
        for(int i=idx;i<nums.size();i++){
            if(nums[i]==1){swap(nums[idx],nums[i]);idx++;}
        }
    }
};