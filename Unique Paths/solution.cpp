class Solution {
public:
    int uniquePaths(int m, int n) {
        int rights = m-1;
        int downs = n-1;
        vector<vector<int>>memo;
        for(int i = 0; i<n; i++){
            vector<int>row;
            for(int j = 0; j<m; j++){
                row.push_back(-1);
            }
            memo.push_back(row);
        }
        return paths(rights,downs,memo);
    }
private:
    int paths(int r, int d, vector<vector<int>>& memo){
        if(memo[d][r] != -1)
            return memo[d][r];
        if(r == 0 || d == 0)
            memo[d][r] = 1;
        else memo[d][r] = paths(r-1,d,memo) + paths(r,d-1,memo);
        return memo[d][r];
    }
};
