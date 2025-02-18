//Using Backtracking
//TC->O((N+1)!*N)
//SC-> O(N)
class Solution {
public:
    bool match(string nums, string pattern){
        for(int i =0; i<pattern.size(); i++){
            if(pattern[i]=='I' && nums[i]>nums[i+1] || pattern[i]=='D' && nums[i]<nums[i+1]){
                return false;
            }
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string nums = "";

        for(int i =1; i<=n+1; i++){
            nums.push_back(i+'0'); 
        }
        
        while(!match(nums,pattern)){
            next_permutation(nums.begin(),nums.end());
        }
        return  nums;    
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Using Stack
//TC->O(N) + 2*(O(N)) ~ O(N)
//SC-> O(N)-->for stack storing n+1 element
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num ="";
        stack<char>st;
        int counter = 1;

        for(int i =0; i<=n; i++){
            st.push(counter + '0');
            counter++;
            
            if(i==n || pattern[i]=='I'){
                while(!st.empty()){
                    num+=st.top();
                    st.pop();
                }
           }
        }
       
        return num;
        
    }
};
