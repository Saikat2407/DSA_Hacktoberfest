https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int firstIndex = firstOccurence(nums,target);
        int lastIndex = lastOccurence(nums,target);
        res.push_back(firstIndex);
        res.push_back(lastIndex);
        return res;
    }
    
    int firstOccurence(vector<int>& nums, int target){
        int mid,l = 0,r = nums.size()-1;
        int index = -1;
        
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] == target){
                index = mid;
                r = mid-1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return index;
    }
    
    int lastOccurence(vector<int>& nums, int target){
        int mid,l = 0,r = nums.size()-1;
        int index = -1;
        
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid] == target){
                index = mid;
                l = mid+1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return index;
    }
};