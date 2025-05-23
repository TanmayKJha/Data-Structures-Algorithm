class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int>set1(nums1.begin(),nums1.end());
        unordered_set<int>set2(nums2.begin(),nums2.end());

        vector<int> arr1,arr2;

        for(int num: set1){
            if(set2.find(num)==set2.end()){
                arr1.push_back(num);
            }
        }

        for(int num: set2){
            if(set1.find(num)==set1.end()){
                arr2.push_back(num);
            }
        }
        return {arr1,arr2};
    
    }
};
