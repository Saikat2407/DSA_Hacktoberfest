/*
* Problem Statement: Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
* Link : https://leetcode.com/problems/product-of-array-except-self/
* Example 1:
*   Input: nums = [1,2,3,4]
*   Output: [24,12,8,6]
*
* Example 2:
*   Input: nums = [-1,1,0,-3,3]
*   Output: [0,0,9,0,0]
*
*/

/* Solution Approach: 
1. Create left and right prefixProduct arrays. 
2. Multiply corresponding elements of lp[] and rp[], store the result in resultant array.
*/

Code:

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] lp = new int[n];    //left prefixProduct Array
        int[] rp = new int[n];    //right prefixProduct Array
        int[] answer = new int[n];
        lp[0] = 1;
        rp[n-1] = 1;
        
        for(int i=1; i<n;i++){
            lp[i] = lp[i-1] * nums[i-1];
        }                     
        // for eg-1: lp = [1, 1, 2, 6]
        
        for(int i=n-2; i>=0;i--){
            rp[i] = rp[i+1] * nums[i+1];
        }
        // for eg-1: lp = [24, 12, 4, 1]

        for(int j=0; j<n;j++){
            answer[j] = lp[j] * rp[j];
        }
        //answer = [24,12,8,6]
        
        return answer;    
    }
}

