class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sum =0;
        for(int i =0; i<grid[0].size(); i++){
            sum+=grid[0][i];
        }
        long long FirstRowRemSum = sum; // calculated first row sum
        long long SecondRowRemSum = 0;
        long long minimizedSum = LONG_LONG_MAX;

        for(int robot1 = 0; robot1<grid[0].size(); robot1++){
            //if robot 1 takes down path from row 0 then,
            FirstRowRemSum-=grid[0][robot1];

            long long bestOfRobot2 = max(FirstRowRemSum, SecondRowRemSum );

            //if robot 1 takes down path from any column number apart from 0th col
            SecondRowRemSum+=grid[1][robot1];

            minimizedSum = min(minimizedSum, bestOfRobot2);
        }
         return minimizedSum;
    }
};
