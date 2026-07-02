class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==0)return 1;
            else return 0;
        }
        int i=0;
        while(i<nums.size()){
            int correctIndex=nums[i]-1;
            if(correctIndex<0){i++;continue;}
            else if(nums[i]!=nums[correctIndex]){swap(nums[i],nums[correctIndex]);}
            else i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)return i+1;
        }
        return 0;
    }
};