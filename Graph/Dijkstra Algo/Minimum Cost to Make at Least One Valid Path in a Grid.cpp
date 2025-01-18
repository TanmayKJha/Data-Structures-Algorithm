class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<int>> result(m, vector<int>(n,INT_MAX));
        pq.push({0, {0, 0}});
        result[0][0] = 0;


        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int cost = curr.first;
            auto x = curr.second.first;
            auto y = curr.second.second;

            
            int dx[] = {1,0,-1,0};
            int dy[] = {0,1,0,-1};

            for(int dir=0; dir<4; dir++){
            int newx = x + dx[dir];
            int newy = y + dy[dir];

            if(newx>=0 && newx<m && newy >=0 && newy<n){
                int gridDir = grid[x][y];
                int dirCost = 0;
                if(gridDir==1  && dir!=1|| 
                    gridDir==2 && dir!=3||
                    gridDir==3 && dir!=0|| 
                    gridDir==4 && dir!=2){
                    dirCost =1;
                }
               
                int newCost = cost+ dirCost;

                if(newCost < result[newx][newy]){
                    result[newx][newy]=newCost;
                    pq.push({newCost,{newx,newy}});
                }
              
            }

        }

    }
    return result[m-1][n-1];
        
    }
};
