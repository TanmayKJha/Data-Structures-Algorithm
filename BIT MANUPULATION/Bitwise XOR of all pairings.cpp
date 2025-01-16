/////////////////////////////////////////////////////////////////////////////////////USING MAP/////////////////////////////////////////////////////////////
//TC - O(N)
//SC -O(N)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,long long> mp;
        int m = nums1.size();
        int n = nums2.size();

        for(int i=0; i<m;i++){
            mp[nums1[i]] += n;
        }
        for(int i=0;i<n;i++){
            mp[nums2[i]]+=m;
        }

        int result=0;

        for(auto &num: mp){
            if((num.second%2)!=0){
               result = result^(num.first);
            }
        }
        return result;
        
    }
};

////////////////////////////////////////////////////////////////////////////////////////USING BRUTE FORCE GAVE MLE///////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> result(m*n);

        int index =0;

        for(int i =0;i<m; i++){
            for(int j = 0; j<n; j++){
                result[index] = nums1[i]^nums2[j];
                index++;
            }
        }
        int ans  =0;
        for(int i =0;i<result.size();i++){
            ans^=result[i];
        }
        return ans;
    }
};
///////////////////////////////////////////////////////////////////USING XOR PROPERTIES////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TC -->O(N)
//SC -->O(1)
class Slution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        int result =  0;
        
        if (m % 2 != 0 && n % 2 == 0) { // nums1 is odd, so we traverse on nums2
            for (int i = 0; i < n; i++) {
                result ^= nums2[i];
            }
            return result;
        }
        
        if (m % 2 == 0 && n % 2 != 0) { // nums2 is odd, so we traverse on nums1
            for (int i = 0; i < m; i++) {
                result ^= nums1[i];
            }
            return result;
        }
        
        if (m % 2 == 0 && n % 2 == 0) { // both are even, so total output 0
            return 0;
        }
        
        // Both m and n are odd, so XOR all elements in both arrays
        for (int i = 0; i < m; i++) {
            result ^= nums1[i];
        }
        for (int i = 0; i < n; i++) {
            result ^= nums2[i];
        }

        return result;
    }
};
