class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>memo;
        for(int i = 0; i<nums.size(); i++){
            memo.push_back(-1);
        }
        return calcRob(nums,0,memo);
    }
private:
    int calcRob(vector<int>& nums, int i, vector<int>& memo){
        if(i>=nums.size())
            return 0;
        else if(i == nums.size()-1)
            return nums[i];
        if(memo[i] != -1)
            return memo[i];
        memo[i] = max(nums[i] + calcRob(nums,i+2,memo),calcRob(nums,i+1,memo));
        return memo[i];
    }
};
