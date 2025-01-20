class Solution {
public:
    bool isPossible(vector<int>& weights, int mid, int days){
        int noOfDay = 1; //start with the first day
        int add = 0;
        for(int i =0; i<weights.size(); i++){
            if(add+weights[i]>mid){
                noOfDay++;
                add = weights[i];
            }else{
                add+=weights[i];
            }
        }

    if(noOfDay<=days){
        return true;
    }
       return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),weights.end()); //ship's capacity cannot be smaller than the heaviest package.
        int sum = 0;
        for(int i =0;i <weights.size(); i++){
            sum+=weights[i];
        }
        int end= sum;
        int mid = start +(end-start)/2;

        while(start<end){
            if(isPossible(weights,mid,days)){
                end = mid;
            }else{
                start = mid+1;
            }
            mid = start +(end-start)/2;
        }
        return start;
    }
};
