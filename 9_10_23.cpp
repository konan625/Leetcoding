https : // leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
        Given an array of integers nums sorted in non -
        decreasing order,
    find the starting and ending position of a given target value.

    If target is not found in the array,
    return [ -1, -1 ].

    You must write an algorithm with
    O(log n) runtime complexity.

    class Solution
{
public:
    int first(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                r = mid - 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

    int last(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2);
        ans[0] = first(nums, target);
        ans[1] = last(nums, target);
        return ans;
    }
};