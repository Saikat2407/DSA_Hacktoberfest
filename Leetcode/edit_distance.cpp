// leetcode problem link : https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string A, string B) {
         int N=A.size(), M=B.size();
        int dp[N+1][M+1];
        
        for(int i=0;i<=N;i++)dp[i][0]=i;
        for(int j=0;j<=M;j++)dp[0][j]=j;
        
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
               if(A[i-1]==B[j-1])
               {
                   dp[i][j]=dp[i-1][j-1];
               }
              else
              { 
               int op1=dp[i-1][j];
                  int op2=dp[i][j-1];
                   int op3=dp[i-1][j-1];
                  dp[i][j]=1+min({op1,op2,op3});
                  
              }
            }
        }
        return dp[N][M]; 
    }
};
