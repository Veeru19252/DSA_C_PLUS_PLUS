class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0;
        if(nums.size()==1){
            if(nums[i]!=1)return{1};
        }
        while(i<nums.size()){
            int a=nums.at(i)-1;
            if(nums[a]!=nums[i])swap(nums[a],nums[i]);
            else i++;
        }vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)ans.push_back(i+1);
        }
        return ans;
    }
};