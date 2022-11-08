//Problem link :https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/
//contributed by :nithish12345678
// time complexity : O( n) using HashMap

import java.util.*;

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<Integer>();
        // Using HashMap
        HashMap<Integer, Integer> hmap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (hmap.containsKey(nums[i])) {
                ans.add(nums[i]);
            } else {
                hmap.put(nums[i], 1);
            }

        }

        // Using HashSet
        // HashSet<Integer> hset=new HashSet<>();
        // for(int i=0;i<nums.length;i++){
        // if(hset.contains(nums[i])){
        // ans.add(nums[i]);
        // }
        // else{
        // hset.add(nums[i]);
        // }
        // }
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

// findDuplicates( nums);
// }
// }