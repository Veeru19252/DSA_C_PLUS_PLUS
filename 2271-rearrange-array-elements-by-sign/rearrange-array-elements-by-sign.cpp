class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int idx=0;
        int neg=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                ans[idx]=nums[i];
                idx=idx+2;
            }
            if(nums[i]<0){
                ans[neg]=nums[i];
                neg=neg+2;
            }
        }
        return ans;
    }
};