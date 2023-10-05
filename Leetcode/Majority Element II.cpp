class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Jai Shree Ram
        // Not Over Until I Win
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto & i : nums) {
            mp[i]++;
        }
        for(auto & i : mp) {
            if(i.second > n / 3) {
                ans.emplace_back(i.first);
            }
        }
        return ans;
    }
};
