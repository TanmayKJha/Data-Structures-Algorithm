class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = nums.size();
        // create min heap for 0 to k elements
        for(int i =0;i<k;i++){
            pq.push(nums[i]);
        }
        // add n-k elements only if the  element from (n-k) array is > pq.top();
        for(int i =k;i<n;i++){
            int element = nums[i];
            if(element>pq.top()){
                pq.pop();                     // this for loop creates the max heap of k size largest element
                pq.push(element);
            }
        }
        return pq.top();             // elemnt on the top of the queue will be thr k the largest element
        
    }
};
