class Solution {
public:
    int totalNQueens(int n) {
        set<int>col;
        set<int>diagL;
        set<int>diagR;
        return place(0,n,col,diagL,diagR);
    }
    
    int place(int i, int n, set<int>& col, set<int>& diagL, set<int>& diagR) {
        if(i == n){
            return 1;
        }
        int count = 0;
        for(int j = 0; j<n; j++){
            if(col.find(j) != col.end() || diagL.find((i-j)) != diagL.end() || diagR.find((i+j)) != diagR.end())
                continue;
            col.insert(j);
            diagL.insert(i-j);
            diagR.insert(i+j);
            count += place(i+1,n,col,diagL,diagR);
            col.erase(j);
            diagL.erase(i-j);
            diagR.erase(i+j);
        }
        return count;
    }
};
