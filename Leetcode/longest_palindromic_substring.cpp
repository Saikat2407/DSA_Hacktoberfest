/*https://leetcode.com/problems/longest-palindromic-substring/*/

class Solution {
public:
    int ispal(string s,int i,int j){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int start=0,a=0;
        for(int i=0;i<s.length();i++){
            int b = ispal(s,i,i);
            int c= ispal(s,i,i+1);
            if(a < max(b,c)){
                a=max(b,c);
                start = i - (a-1)/2;
            }
        }
        return s.substr(start,a);
    }
};