class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int a=nums[i]-1;
            if(nums[a]!=nums[i])swap(nums[a],nums[i]);
            else i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)return {nums[i],i+1};
        }
        return {};
    }
};