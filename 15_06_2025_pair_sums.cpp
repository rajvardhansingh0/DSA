#include <vector>
#include <unordered_map>

std::vector<std::pair<int, int>> pairSums(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            result.push_back({nums[i], complement});
        }
        numMap[nums[i]] = i;
    }
    return result;
}