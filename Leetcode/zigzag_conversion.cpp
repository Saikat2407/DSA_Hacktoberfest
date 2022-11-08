/*https://leetcode.com/problems/zigzag-conversion/*/
class Solution {
public:
    string convert(string s, int n) {
        if(n==1){
            return s;
        }
        vector<vector<char>>v;
        for(int i=0;i<n;i++){
            vector<char> a;
            v.push_back(a);
        }
        int inc=1,it=0;
        for(int i=0;i<s.length();i++){
            if(it==0){
                inc=1;
            }else if(it==n-1){
                inc=-1;
            }
            v[it].push_back(s[i]);
            it+=inc;
        }
        string q="";
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                q+=v[i][j];
            }
        }
        return q;
    }
};