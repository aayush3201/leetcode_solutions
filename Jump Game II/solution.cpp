class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>memo;
        for(int i = 0; i<nums.size(); i++){
            memo.push_back(-1);
        }
        return calcJumps(nums,0,memo);
    }
private:
    int calcJumps(vector<int>& nums, int pos, vector<int>& memo){
        if(memo[pos] != -1)
            return memo[pos];
        if(pos == nums.size()-1)
            memo[pos] = 0;
        else if(nums[pos]>=(nums.size()-pos-1))
            memo[pos] = 1;
        else{
            int minSteps = INT_MAX-1;
            for(int i = 1; i<=nums[pos]; i++){
                int steps = 1+calcJumps(nums,pos+i,memo);
                minSteps = min(steps,minSteps);
            }
            memo[pos] = minSteps;
        }
        return memo[pos];
    }
};
