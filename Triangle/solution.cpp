class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo;
        for(int i = 0; i<triangle.size(); i++){
            vector<int>row;
            for(int j = 0; j<triangle[i].size(); j++)
                row.push_back(INT_MIN);
            memo.push_back(row);
        }
        return calcTotal(triangle,0,0,memo);
    }
    int calcTotal(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& memo){
        if(memo[i][j] != INT_MIN)
            return memo[i][j];
        if(i == triangle.size()-1)
            memo[i][j] = triangle[i][j];
        else memo[i][j] = triangle[i][j] + min(calcTotal(triangle,i+1,j,memo),calcTotal(triangle,i+1,j+1,memo));
        return memo[i][j];
    }
};
