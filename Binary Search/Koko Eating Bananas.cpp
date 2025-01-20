class Solution {
public:
    bool PossibleToEat(vector<int>&piles, int mid, int h){
        int totalHours = 0; //actual no of hours(time) taken to eat all the bannanas from n piles
        for(int i =0; i<piles.size(); i++){
            totalHours +=piles[i]/mid; //total time taken to eat ith pile banana

            if(piles[i]%mid!=0){
                totalHours++;
            }
        }
        if(totalHours<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        int mid = start +(end-start)/2; //if koko can eat mid number of bananas within h hours

        while(start<end){
            if(PossibleToEat(piles,mid,h)){
                end = mid;
            }else{
                start = mid+1;
            }
            mid = start +(end-start)/2; 
        }
        return start;

    }
};
