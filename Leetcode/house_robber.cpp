// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        
        if ( nums.size() >= 2 ){
            dp[1] = max(nums[0], nums[1]);

            for ( int i=2; i<nums.size(); i++){
                for( int j=0; j<i-1; j++ ){
                    dp[i] = max(dp[i-1], nums[i]+dp[j]);
                }

            }
        }

        return dp[nums.size()-1];        
    }
};