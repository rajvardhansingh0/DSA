#include <vector>
#include <algorithm>

std::vector<int> solve(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> result;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            result.push_back(nums1[i]);
            i++;
        } else {
            result.push_back(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size()) {
        result.push_back(nums1[i]);
        i++;
    }
    while (j < nums2.size()) {
        result.push_back(nums2[j]);
        j++;
    }
    return result;
}