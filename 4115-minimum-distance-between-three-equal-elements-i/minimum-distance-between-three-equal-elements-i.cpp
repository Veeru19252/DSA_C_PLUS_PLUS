class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minval=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1;
                if(nums[i]==nums[j]){
                    while(k!=n){
                        if(nums[j]==nums[k] && nums[i]==nums[k]){
                            minval=min(minval,abs(i-j)+abs(j-k)+abs(k-i));

                        }
                        k++;
                    }
                }
            }
        }
        return (minval==INT_MAX)? -1:minval;
    }
};