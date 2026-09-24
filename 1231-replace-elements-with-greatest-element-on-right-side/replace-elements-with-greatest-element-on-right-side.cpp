class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int prev=INT_MIN;
        int idx=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(prev<nums[i]){
                prev=nums[i];
            }
            ans[idx]=prev;
            idx++;
        }
        ans[nums.size()-1]=-1;
        reverse(ans.begin(),ans.end()-1);
        return ans;
    }
};