//Returning the index of a specific element!!

package com.saikat;

public class Main {

    public static void main(String[] args) {
        int[] arr = {12, 45, 67, 9, 0, -9, 100};
        int target = 100;
        int ans = linearSearch(arr, target);
        System.out.println(ans);
    }

    static int linearSearch(int[] arr, int target){
        if (arr.length == 0){
            return -1;
        }
        for (int index = 0; index < arr.length; index++) {
            int element = arr[index];
            if(element == target){
                return index;
            }
//            return index;
        }
        return -1;
    }
}
