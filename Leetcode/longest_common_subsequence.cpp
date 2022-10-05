
// leetcode problem link : https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
     int n=s1.size();
     int m=s2.size();
        vector<int>first(m+1),second(m+1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    second[j]=1+first[j-1];
                else second[j]=max(first[j],second[j-1]);
            }
            first=second;
        }
        return first[m];
    }
};

