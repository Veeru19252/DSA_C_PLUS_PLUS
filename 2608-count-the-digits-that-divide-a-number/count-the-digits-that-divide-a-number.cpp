class Solution {
public:
    int countDigits(int num) {
        int ans=num;
        int count=0;
        while(ans>0){
            int k=ans%10;
            if(num%k==0)count++;
            ans/=10;
        }return count;
    }
};