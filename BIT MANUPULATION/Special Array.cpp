//USING BIT MAGIC "and &" logic
//if n is even then n&1 ==0 //If n is odd n&1 ==1
//for odd no the rightmost bit is 1 and for even rightmost bit is 0
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return true; 
        }
        for(int i=0; i<n-1; i++){
            if((nums[i]&1) == (nums[i+1]&1)){
                return false;
            }else{
                continue;
            }         
        }
        return true;
    }
};
