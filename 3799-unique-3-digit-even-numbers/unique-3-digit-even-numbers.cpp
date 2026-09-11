class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]==0) continue; // if the numbers is 0, skip the number
            for(int j=0;j<n;j++){
                if(i==j) continue; // since we can't pick the picked number  
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue; // since we can't pick the picked numbers
                    if(digits[k]%2 != 0) continue; // skip  if number is not even since it is ones place
                    int num=digits[i]*100 + digits[j]*10 + digits[k]; // forming the three digit number

                    st.insert(num);
                }
            }
        }
        return st.size();
    }
};