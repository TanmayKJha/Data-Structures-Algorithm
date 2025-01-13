class Solution {
public:

    int firstOccurence(vector<int>& nums, int target){
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int idx = -1;

        while(s<=e){
            int mid = s +(e-s)/2;

            if(nums[mid]==target){
               idx = mid;
               e = mid-1;
            }else if(nums[mid]<target){
               s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return idx;
    }

    int LastOccurence(vector<int>& nums, int target){
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int idx = -1;

        while(s<=e){
            int mid = s +(e-s)/2;

            if(nums[mid]==target){
               idx = mid;
               s = mid+1;
            }else if(nums[mid]<target){
               s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        int first =  firstOccurence(nums,target);
        int last =  LastOccurence(nums,target);

        result.push_back(first);
        result.push_back(last);
       
       return result; 
    }
};
