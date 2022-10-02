// LEET CODE PROBLEM
// https://leetcode.com/problems/merge-sorted-array/
// Time Complexity: O(n)
// Space Complexity: O(1)
// merge two sorted arrays & merge into it in first array
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = nums1.size() - 1;
        while (i >= 0 and j >= 0)
        {
            if (nums1[i] <= nums2[j])
            {
                nums1[k--] = nums2[j--];
            }
            else
            {
                nums1[k--] = nums1[i--];
            }
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};