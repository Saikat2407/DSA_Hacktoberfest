import java.util.Arrays;

// binary search in 2d arrays
// array is sorted row-wise and column-wise
/*
  [
  [10, 20, 30, 40],
  [15, 25, 35, 45],
  [28, 29, 37, 49],
  [33, 34, 38, 50]
  ]
 */

public class BinarySearch2D {
	
	public static void main(String[] args) {
		int[][] arr = {
				  {10, 20, 30, 40},
				  {15, 25, 35, 45},
				  {28, 29, 37, 49},
				  {33, 34, 38, 50}
		};
		System.out.println(Arrays.toString(search(arr,37)));
	}

	public static int[] search(int[][] arr, int target) {
		int r=0;
		int c= arr.length-1;
		while(r<arr.length && c>=0) {
			if(target == arr[r][c]) {
				return new int[] {r,c};
			}
			else if(target> arr[r][c]) {
				r++;
			}
			else {
				c--;
			}
		}
		return new int[] {-1,-1};
	}
}
