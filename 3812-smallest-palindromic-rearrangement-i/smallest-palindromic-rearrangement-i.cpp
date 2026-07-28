class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1)return s;
        int mid=s.size()/2;
        int n=s.size();
        sort(s.begin(),s.begin()+mid);
        for(int i=0;i<mid;i++){
            s[n-mid+i]=s[i];
        }
        reverse(s.end()-mid,s.end());
        return s;
    }
};