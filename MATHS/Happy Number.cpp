//BRUTE FORCE //USIG HASH SET
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        int rem;
        int square_sum;
        while(1){
            square_sum = 0;
            while(n>0){
                rem = n%10;
                square_sum += rem*rem;
                n/=10;
            }
            if(square_sum==1){
                return true;
            }else if(st.find(square_sum)!=st.end()){
                   return false;
            }
            st.insert(square_sum);
            n = square_sum;
        }
        return false;
    }
};
