class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0,y=0;
        for(int i=0;i<nums.size();i++){
            x=x^nums[i];
            y=y^i;
        }
        y^=nums.size();
        return x^y;
    }
};