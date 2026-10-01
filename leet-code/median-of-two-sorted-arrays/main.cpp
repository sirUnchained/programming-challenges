/*
# Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:
* nums1.length == m
* nums2.length == n
* 0 <= m <= 1000
* 0 <= n <= 1000
* 1 <= m + n <= 2000
* -106 <= nums1[i], nums2[i] <= 106
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // merge 2 vectors
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        // sorting
        std::sort(nums1.begin(), nums1.end());

        // finding answer
        double result = 0.0;
        int center = 0;

        if (nums1.size() % 2 == 0)
        {
            center = floor(nums1.size() / 2);
            result = double(nums1[center] + nums1[center - 1]) / 2;
        }
        else
        {
            center = ceil(nums1.size() / 2);
            result = nums1[center];
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();

    std::vector<int> v1{1, 3};
    std::vector<int> v2{2, 4};

    std::printf("%f\n", s.findMedianSortedArrays(v1, v2));

    return 0;
}
