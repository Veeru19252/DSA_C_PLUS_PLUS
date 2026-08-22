class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        long long a=x;
        if(-9<=x && x<=9)return x;
        if(x>0){
            while(a>0){
                int lastdigit=a%10;
                rev=rev*10+lastdigit;
                a/=10;
            }
        }else{
            a=-a;
            while(a>0){
                int lastdigit=a%10;
                rev=rev*10+lastdigit;
                a/=10;
            }
            rev=-rev;
        }
        if(rev<INT_MIN || rev>INT_MAX)return 0;
        return rev;
    }
};