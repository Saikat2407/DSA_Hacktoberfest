// Question Link:- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 

import java.util.Arrays;


public class FirstAndLastPosititon {
	
	public static void main(String[] args) {
		int[] arr = {5,7,7,7,8,8,10};
		int target = 7;
		System.out.println(Arrays.toString(searchRange(arr,target)));
	}

	public int[] searchRange(int[] nums, int target) {
        int[] res = new int [2];
		res[0] = getIndex(nums, target, true);
		res[1] = getIndex(nums, target, false);
        
        return res;
    }
    public static int getIndex(int[] arr, int target, boolean firstOccurance) {
		int ans=-1;
		
		int start =0;
		int end = arr.length-1;
		
		while(start<=end) {
			int mid = start + (end-start)/2;
			
			if(target<arr[mid]) {
				end =mid-1;
			}
			else if(target>arr[mid]) {
				start=mid+1;
			}
			else if(target == arr[mid]){
				ans = mid; //probable ans
				if(firstOccurance) {
					end = mid -1;
				}
				else {
					start = mid+1;
				}
			}
		}
		
		return ans;
	}
}

