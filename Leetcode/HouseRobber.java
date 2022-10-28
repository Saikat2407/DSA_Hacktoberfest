class Solution 
{
    public int rob(int[] a) 
    {
        int n = a.length;
        if(n==1)
            return a[0];
        if(n==2)
            return Math.max(a[0], a[1]);
        int[] dp = new int[n+2];
        for(int i=n-1; i>=0; i--)
            dp[i] = Math.max(dp[i+2] + a[i], dp[i+1]);
        return dp[0];
    }
}
