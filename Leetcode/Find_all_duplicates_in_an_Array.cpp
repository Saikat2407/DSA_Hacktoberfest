//https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> count;
        vector<int> ans;
        for(int num : nums){
            if(count.find(num) == count.end()){
                count[num] = 1;
            }else{
                count[num]++;
                ans.push_back(num);
            }
        }
        return ans;
    }
};

