class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        int a=n;
        while(a>=1){
            int k=a%10;
            a/=10;
            mp[k]++;
        }
        int k=0;
        for(auto i:mp){
            k+=(i.first)*(i.second);
        }
        return k;
    }
};