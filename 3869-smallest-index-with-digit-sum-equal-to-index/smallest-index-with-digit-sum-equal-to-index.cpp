class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int ans=0;
            while(val>0){
                int rem=val%10;
                ans+=rem;
                val/=10;
            }
            if(ans==i)return i;
        }return -1;
    }
};