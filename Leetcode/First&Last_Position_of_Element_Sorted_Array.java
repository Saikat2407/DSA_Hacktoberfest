//Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//contributed by :nithish12345678
// time complexity : O(log n) using Binary Search technique

class Solution {
    public static int BinSearch(int arr[], int l, int h,
            int target, int flag) {
        // flag =0 -> First position of Element
        // flag =1 -> Last Position of Element
        if (h >= l) {
            // to get First position of Element
            if (flag == 0) {
                int mid = (h + l) / 2;
                if ((mid == 0 || target > arr[mid - 1]) && arr[mid] == target)
                    return mid;
                else if (target > arr[mid])
                    return BinSearch(arr, (mid + 1), h, target, 0);
                else
                    return BinSearch(arr, l, (mid - 1), target, 0);

            }
            // to get Last position of Element
            else {
                int mid = (h + l) / 2;
                if ((mid == arr.length - 1 || target < arr[mid + 1]) && arr[mid] == target)
                    return mid;
                else if (target >= arr[mid])
                    return BinSearch(arr, (mid + 1), h, target, 1);
                else
                    return BinSearch(arr, l, (mid - 1), target, 1);
            }
        }
        return -1;

    }

    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        // First position of Element
        ans[0] = BinSearch(nums, 0, nums.length - 1, target, 0);
        // Last position of Element
        ans[1] = BinSearch(nums, 0, nums.length - 1, target, 1);

        return ans;
    }
}

// to verify the above solution
// class main{
// public static void main(String[] args) {

// int [] nums = new int[6];
// nums[0] = 1;
// nums[1] = 2;
// nums[2] = 3;
// nums[3] = 4;
// nums[4] = 1;
// nums[5] = 5;
// int target=1;
// }
// }