#include <vector>
#include <unordered_set>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        if (nums.empty()) {
            return std::vector<std::vector<int>>{};
        }
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result{};
        std::vector<int> data{};
        std::unordered_set<int> visited_indices{};
        backtrack(nums, visited_indices, data, result);
        return result;
    }

private:
    void backtrack(std::vector<int>& nums, std::unordered_set<int>& visited_indices,
                   std::vector<int>& data,
                   std::vector<std::vector<int>>& result) {
        if (data.size() == nums.size()) {
            result.push_back(data);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // check whether the item has been visited already
            if (visited_indices.find(i) != visited_indices.end()) {
                continue;
            }
            // skip the duplicated item
            if (i > 0 && nums[i] == nums[i - 1] &&
                    visited_indices.find(i - 1) == visited_indices.end()) {
                continue;
            }

            data.push_back(nums[i]);
            visited_indices.insert(i);
            backtrack(nums, visited_indices, data, result);
            visited_indices.erase(i);
            data.pop_back();
        }
    }
};