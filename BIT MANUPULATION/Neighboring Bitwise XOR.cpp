class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int n = derived.size();
        vector<int>original(n);  
        //taking the first element of original as 0   
        original[0]=0;   

        for(int i= 0;i<n-1;i++){
            original[i+1]=original[i]^derived[i];
        }
         if(derived[n-1]==(original[n-1]^original[0])){
                return true;
        }

       //taking the first element of original as 1
       original[0]=1;

       for(int i =0; i<n-1; i++){
           original[i+1] = original[i]+derived[i];          
       }
       if(derived[n-1]==(original[n-1]^original[0])){
            return true;
          }

       return false;
    }
};
