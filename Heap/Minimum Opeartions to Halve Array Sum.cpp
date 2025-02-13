class Solution {
public:
    int halveArray(vector<int>& nums) {

        priority_queue<double, vector<double>>pq(nums.begin(),nums.end());
        double totalsum = 0;
        for(int i =0; i<nums.size(); i++){
            totalsum+=nums[i];
        }
        double currentSum = totalsum;
        double halfSum = totalsum/2;

        int count = 0;

        while(currentSum>halfSum){
            double maxEle = pq.top();
            pq.pop();
            double reducedEle = maxEle/2.0;
            pq.push(reducedEle);
            currentSum-=(maxEle-reducedEle);
            count++;           
        }
        return count;
    }
};
