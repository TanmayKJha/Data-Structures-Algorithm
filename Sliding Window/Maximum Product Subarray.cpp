class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
        int maxProduct = INT_MIN;
        int left = 0;
        for(int right =0; right<nums.size(); right++){
            int product = 1;
            product *= nums[right];
            while(left<=right){
                 maxProduct = max(maxProduct,product);
            }            
        }
        return maxProduct;
    }
};
