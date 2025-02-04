//BRUTE FORCE //LINEAR SEARCH //TC --> O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i =1;
        int j = 0;
        int missingCount = 0;
        while(missingCount<k){
            if(j<arr.size() && arr[j]==i){
                j++;
            }else{
                missingCount++;
                if(missingCount==k){
                    return i;
                }
            }
            i++;
        }
        return -1; 
    }
};
