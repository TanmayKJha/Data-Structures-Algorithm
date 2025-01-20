class Solution {
public:
    int findPivot(vector<int>& nums){
        int n = nums.size();
        int start =0;
        int end = n-1;
        int mid = start +(end-start)/2;

        while(start <end){
            if(nums[mid]>nums[end]){
                start = mid +1;
            }else{
                end = mid;
            }
            mid = start +(end-start)/2;

        }
        return start;
    }
    int binarySearch(vector<int>& nums, int target, int s, int e){
        int mid = s +(e-s)/2;
        int ele = -1;

        while(s<=e){
            if(nums[mid]==target){
                ele = mid;
                return mid;
            }else if(nums[mid]>target){
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s +(e-s)/2;
        }
        return ele;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int min_idx = findPivot(nums); //this will give me the index of the minimum element in an array

        int idx = binarySearch(nums,target,0,min_idx-1);  // search minimum elemnet on left half
        if(idx!=-1){
            return idx;
        }else{
            idx = binarySearch(nums,target,min_idx,n-1);  //search minimum on right half
        }
        return idx;
    }
};
