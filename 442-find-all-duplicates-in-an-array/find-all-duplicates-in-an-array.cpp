class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int a=nums[i]-1;
            if(nums[i]!=nums[a])swap(nums[i],nums[a]);
            else i++;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)ans.push_back(nums[i]);
        }
        return ans;
    }
};