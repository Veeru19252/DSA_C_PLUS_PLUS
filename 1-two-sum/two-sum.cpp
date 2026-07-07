class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
    unordered_map<int,int> m; // value -> index
    for(int i=0;i<(int)v.size();i++){
        int complement = target - v[i];
        auto it = m.find(complement);
        if(it != m.end()){
            return {it->second, i};
        }
        m[v[i]] = i;
    }
    return {-1,-1};
    }
};