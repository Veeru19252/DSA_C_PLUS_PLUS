class Solution {
public:
    int reverseDegree(string s) {
        long long ans=0;
        for(int i=0;i<s.size();i++){
            long long val=26-(s[i]-'a');
            ans=ans+((i+1)*val);
        }return ans;
    }
};