class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numsNewLength =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[numsNewLength] = nums[i];
                numsNewLength++;
            }
        }
       return numsNewLength;
    }
};
