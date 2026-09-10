class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size()<26)return false;
        unordered_map<int,int>mp;
        for(int i=0;i<sentence.size();i++){
            mp[sentence[i]-'a']++;
        }
        if(mp.size()==26)return true;
        return false;
    }
};