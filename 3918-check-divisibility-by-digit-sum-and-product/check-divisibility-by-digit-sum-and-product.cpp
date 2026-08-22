class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long product=1;
        int a=n;
        while(a>0){
            int lastdigit=a%10;
            sum+=lastdigit;
            product*=lastdigit;
            a/=10;
        }return n%(sum+product)==0;
    }
};