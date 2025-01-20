class Solution {
public:
    bool isPossible(vector<int>& time, long long mid , int totalTrips){
        long long NumberTrips = 0;
        for(int i =0; i<time.size(); i++){
            NumberTrips+= mid/time[i];
        }
        if(NumberTrips>=totalTrips){
            return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start =1;
        long long end  = (long long)*min_element(time.begin(),time.end()) * totalTrips;
        long long mid = start +(end-start)/2;
        while(start<end){
            if(isPossible(time,mid,totalTrips)){
                end = mid;
            }else{
                start = mid+1;
            }
            mid = start +(end-start)/2;        
        }
        return start;             
    }
};
