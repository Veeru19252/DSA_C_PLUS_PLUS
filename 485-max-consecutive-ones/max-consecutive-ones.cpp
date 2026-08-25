class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int idx=0;
        int idx_len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                idx=i+1;
            }
            idx_len=max(idx_len,i-idx+1);
        }
        return idx_len;
    }
};