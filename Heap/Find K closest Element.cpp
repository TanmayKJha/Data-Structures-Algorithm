class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    int n = arr.size();
    vector<int> result;
    
    for(int i =0; i<arr.size(); i++){
        int diff = abs(arr[i]-x); 

        pq.push({diff,arr[i]});
    }

    while(k--){
        pair<int,int> ele = pq.top();
        pq.pop();
        result.push_back(ele.second);
 }

    sort(result.begin(),result.end());
    return result;
        
    }
};
