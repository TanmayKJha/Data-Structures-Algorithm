//TC -->O( log(min(m+n)) ) //Using Binary Search
//TC -->O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0, high = m;
        while(low <= high) {
            
            int Px = low + (high - low) / 2;
            int Py = (m + n + 1) / 2 - Px;
            
            int x1, x3, x2, x4;
            
            if (Px == 0) 
                x1 = INT_MIN;
            else 
                x1 = nums1[Px - 1];
            
            if (Px == m) 
                x3 = INT_MAX;
            else 
                x3 = nums1[Px];
            
            if (Py == 0) 
                x2 = INT_MIN;
            else 
                x2 = nums2[Py - 1];
            
            if (Py == n) 
                x4 = INT_MAX;
            else 
                x4 = nums2[Py];
            
            if (x1 <= x4 && x2 <= x3) {
                if ((m + n) % 2 == 0)
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
                
                return max(x1, x2);
            } else if (x1 > x4) {
                high = Px - 1;
            } else {
                low = Px + 1;
            }
        }
        
        return -1;
    }
};
