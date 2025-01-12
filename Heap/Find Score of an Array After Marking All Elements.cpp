class Solution {
public:
    // here pair P is defined 
    #define P pair<int,int>
    long long findScore(vector<int>& nums) {

        int n = nums.size();
        // vector where index is markied true or falsi if visited or not
        vector<bool> visited(n,false);   // S.C ->O(n)
        // min heap stores elements of array and their rspective index in pair
        priority_queue<P, vector<P>, greater<P>>pq;
        
        // all the elements of nums array are pushed into i=min heao
        for(int i =0;i<n;i++){  // TC ->0(n)
            pq.push({nums[i],i}); // TC ->O(logn)
        }
        
        long long score = 0;
      
        
        while(!pq.empty()){   // TC-> O(n)
          P minElement = pq.top();
          int element =  minElement.first;
          int idx    = minElement.second;
          pq.pop();           // TC -> log(n)

          if(visited[idx]!=true){ 
             visited[idx]= true;
            //add top elemeent to the score if the above condition is true
            score+=element;
            //check condition for left index element
            if(idx-1>=0 && visited[idx-1]!=true ){
               visited[idx-1]=true;
            }
            //check condition for right index element
            if( idx+1<n && visited[idx+1]!=true){
               visited[idx+1]=true;
            }
          }


        }
        return score;
        
    }
};
