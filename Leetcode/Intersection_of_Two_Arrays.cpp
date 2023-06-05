class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size())
        {
            if (i > 0 && nums1[i] == nums1[i - 1])
            {
                i++;
                continue;
            }
            else if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};