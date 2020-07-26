#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
		if (n < k || k < 0) {
			return std::vector<std::vector<int>>{};
		}
		if (n == k || k == 0) {
			std::vector<std::vector<int>> result{};
			std::vector<int> temp{};
			for (int i = 1; i <= k; ++i) {
				temp.push_back(i);
			}
			result.push_back(temp);
			return result;
		}
		
		std::vector<std::vector<int>> result = combine(n - 1, k - 1);
		for (auto& element : result) {
			element.push_back(n);
		}
		std::vector<std::vector<int>> prevResult = combine(n - 1, k);
		result.insert(result.end(), prevResult.begin(), prevResult.end());
		return result;
    }

    std::vector<std::vector<int>> combine_v2(int n, int k) {
		if (n < k || k == 0) {
			return std::vector<std::vector<int>>{};
		}
		std::vector<std::vector<int>> result{};
		std::vector<int> data{};
		backtrack(n, k, 0, data, result);
		return result;
	}

private:
	void backtrack(int n, int k, int start, std::vector<int>& data,
	          std::vector<std::vector<int>>& result) {
		if (data.size() == k) {
			result.push_back(data);
			return;
		}
		for (int i = start; i < n; ++i) {
			data.push_back(i + 1);
			backtrack(n, k, i + 1, data, result);
			data.pop_back();
		}
	}

};