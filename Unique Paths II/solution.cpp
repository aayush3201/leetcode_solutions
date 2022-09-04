class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>memo;
        for(int i = 0; i<obstacleGrid.size(); i++){
            vector<int>row;
            for(int j = 0; j<obstacleGrid[0].size(); j++){
                row.push_back(-1);
            }
            memo.push_back(row);
        }
        return countPaths(obstacleGrid,0,0,memo);
    }
private:
    int countPaths(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& memo){
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || obstacleGrid[i][j] == 1)
            return 0;
        if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size() - 1)
            return 1;
        if(memo[i][j] != -1)
            return memo[i][j];
        memo[i][j] = countPaths(obstacleGrid,i+1,j,memo) + countPaths(obstacleGrid,i,j+1,memo);
        return memo[i][j];
    }
};
