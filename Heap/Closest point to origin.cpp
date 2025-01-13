class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;

        vector<vector<int>> result;

        for(int i =0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];

            int dis = abs((x*x-0*0)+(y*y-0*0));
            pq.push({dis,points[i]});
        }

        while(k--){
            auto topEle = pq.top();
            pq.pop();
            result.push_back(topEle.second);
        }

        return result;
        
    }
};
