class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int max_ele=INT_MIN;
        int sum=0;
        for(int i=0;i<v.size();i++){
            if(sum<0)sum=0;
            sum+=v.at(i);
            max_ele=max(max_ele,sum);
        }
        return max_ele;
    }
};