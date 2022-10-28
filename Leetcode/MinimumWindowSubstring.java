class Solution 
{
    public String minWindow(String s, String t) 
    {
        int n = s.length(), m = t.length();
        int[] c1 = new int[123];
        int[] c2 = new int[123];
        int k = 0;
        for(int i=0; i<m; i++)
        {
            char c = t.charAt(i);
            if(c1[c] == 0)
                k++;
            c1[c]++;
        }
        int i = 0, j = 0;
        int windowSize = 0;
        String minWindow = "";
        while(j < n)
        {
            char c = s.charAt(j);
            c2[c]++;
            if(c1[c] == c2[c])
                windowSize++;
            while(windowSize == k)
            {
                if(minWindow.isEmpty() || j - i + 1 < minWindow.length())
                    minWindow = s.substring(i, j + 1);
                c = s.charAt(i++);
                c2[c]--;
                if(c2[c] < c1[c])
                    windowSize--;
            }
            j++;
        }
        return minWindow;
    }
}
