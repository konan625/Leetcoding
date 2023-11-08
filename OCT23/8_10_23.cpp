https : // leetcode.com/problems/max-dot-product-of-two-subsequences/
        Given two arrays nums1 and nums2.

        Return the maximum dot product between non -
    empty subsequences of nums1 and nums2 with the same length.

    A subsequence of a array is a new array which is formed from the original array by deleting
    some(can be none) of the characters without disturbing the relative positions of the remaining characters.(ie, [ 2, 3, 5 ] is a subsequence of[1, 2, 3, 4, 5] while[1, 5, 3] is not )
        .

    class Solution
{
public:
    int helper(vector<int> &nums1, vector<int> &nums2, int n1, int n2)
    {
        if (n1 < 0 || n2 < 0)
            return 0;
        // take
        int a = (nums1[n1] * nums2[n2]) + helper(nums1, nums2, n1 - 1, n2 - 1);
        int b = helper(nums1, nums2, n1, n2 - 1);
        int c = helper(nums1, nums2, n1 - 1, n2);
        int d = helper(nums1, nums2, n1 - 1, n2 - 1);

        return max(max(a, b), max(c, d));
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int num : nums1)
        {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }

        for (int num : nums2)
        {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }

        if (firstMax < 0 && secondMin > 0)
        {
            return firstMax * secondMin;
        }

        if (firstMin > 0 && secondMax < 0)
        {
            return firstMin * secondMax;
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        return helper(nums1, nums2, n1 - 1, n2 - 1);
    }
};