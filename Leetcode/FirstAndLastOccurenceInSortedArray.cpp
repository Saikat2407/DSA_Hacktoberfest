//binary search
//Leetcode Question NO. 34
//Find First and Last Position of Element in Sorted Array.
//time: O(logN), space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n == 0) return {-1, -1};
        
        int left = 0, right = n-1;
        
        //find left boundary
        while(left <= right){
            int mid = (left+right) >> 1;
            // cout << left << ", " << mid << ", " << right << endl;
            
            if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        if(left >= n || nums[left] != target){
            return {-1, -1};
        }
        
        vector<int> ans = {left};
        
        //find right boundary
        left = 0;
        right = n-1;
        while(left <= right){
            int mid = (left+right) >> 1;
            // cout << left << ", " << mid << ", " << right << endl;
            
            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        ans.push_back(right);
        
        return ans;
    }
};