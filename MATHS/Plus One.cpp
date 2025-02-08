//Optimized Code
//TC-->O(N)//SC->O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1; i>=0; i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;       
    }
};
/////////////////////////////////////////////////BRUTE FORCE//////////////////////////Causing runtime error--integer overflow//////////////////////////////
//Time complexity --> O(n)+O(1)+O(n)+O(n)+O(n)=O(n)
//Space Complexity--> O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        long long n = digits.size();
        long long ans =0;

        for(int i=0; i<n; i++){  //o(n)
            ans = ans*10 + digits[i];
        }
        ans++;

        while(digits.size()!=0){ //o(n)
            digits.pop_back();//o(1)
        }
        while(ans>0){ //o(n)
            digits.push_back(ans%10);
            ans = ans/10;
        }
        std::reverse(digits.begin(), digits.end()); //o(n)
        return digits;
    }
    
};
