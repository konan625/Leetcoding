https : // leetcode.com/problems/majority-element-ii/
        Given an integer array of size n,
        find all elements that appear more than ⌊ n / 3 ⌋ times.

                                                      class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums;
        int k1 = nums[0], c1 = 1;
        int k2 = nums[0], c2 = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == k1)
            {
                c1++;
            }
            else if (nums[i] == k2)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                k1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0)
            {
                k2 = nums[i];
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == k1)
                c1++;
            if (nums[i] == k2)
                c2++;
        }
        if (c1 > n / 3 && c2 > n / 3)
        {
            if (k1 == k2)
            {
                ans.push_back(k1);
            }
            else
            {
                ans.push_back(k1);
                ans.push_back(k2);
            }
        }
        else if (c1 > n / 3)
        {
            ans.push_back(k1);
        }
        else if (c2 > n / 3)
        {
            ans.push_back(k2);
        }
        return ans;
    }
};