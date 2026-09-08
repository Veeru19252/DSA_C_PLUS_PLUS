class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>suffix(nums.size(),0);
        int sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            suffix[i]=sum;
        }sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(suffix[i]==sum)return i;
        }return -1;
    }
};