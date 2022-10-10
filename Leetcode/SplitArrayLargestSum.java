/*
https://leetcode.com/problems/split-array-largest-sum/

410. Split Array Largest Sum

*/

class Solution {
    public int splitArray(int[] nums, int m) {
      int start = 0;
    int end = 0;
    for (int i = 0; i < nums.length; i++) { // in the end, the loop will contain the maximum item from the array
        start = Math.max(start, nums[i]);
        end += nums[i];
    }

    // binary search 
    while (start < end) {
        // try for the middle as the potential ans
        int mid = start + (end - start) / 2;
        // calculate how many pieces you can divide this in with the max sum
        int sum = 0;
        int pieces = 1;
        for (int num : nums) {
            if (sum + num > mid) {
                // you cannot add this in this subarray, make a new one
                // say you add this num in this new subarray, then sum = num
                sum = num;
                pieces++;
            }
            else {
                sum += num;
            }
        }
        if (pieces > m) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
        return end;
    }  
    }
