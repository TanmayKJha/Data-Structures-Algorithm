class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int n = intervals.size();

        int i =0;
        int j =i+1;

        int count = 0; //stores no of intervals to be removed
        while(j<n){

            vector<int> curren_interval = intervals[i];
            vector<int> next_interval = intervals[j];

            int cs = curren_interval[0];
            int ce = curren_interval[1];

            int ns = next_interval[0];
            int ne = next_interval[1];
            
            if(ce<=ns){ //non overlapping intervals
                i = j;
                j++;
            }else if(ce<=ne){  //overlapping
                j++;
                count++;
            }else if(ce>=ne){  //overlapping
                i=j;
                j++;
                count++;
            }  
        } 
        return count;
    }
};
