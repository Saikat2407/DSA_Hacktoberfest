class Solution {
public:
    int rob(vector<int>& nums) {
     int n=nums.size();
    int prev1=nums[0];//for i-1
        int prev2=0;//for i-2
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick=pick+prev2;//pick=nums[i]+dp[i-2] which is prev2
            }
            int nopick=0+prev1;
            int curr=max(pick,nopick);
            
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};