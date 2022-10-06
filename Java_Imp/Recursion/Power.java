//  https://leetcode.com/problems/powx-n/
public class Pow {
    public static void main(String[] args) {
        System.out.println(myPow(2, 10));
    }
    public static double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        if(x == 0 || x == 1 || n == 1) {
            return x;
        }
        if(n > 1){
            if(n % 2 == 0) {
                double y = x*x;
                return myPow(y,n/2);
            }
            else {
                double y = x*x;
                return x*myPow(y,(n-1)/2);
            }
        }
        else {
            double ans = x*myPow(x, -(n + 1));
            ans = (1/ans);
            return ans;
        }
    }
}