#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>


struct comparator {
    bool operator() (std::pair<int, int> i, std::pair<int, int> j) {
        return i.second < j.second;
    }
} myobject;


class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int, int> indexMap{};
        std::vector<std::pair<int, int> > mypairs{};
        for (int i = 0; i < arr2.size(); ++i) {
            indexMap[arr2[i]] = i;
        }
        for (auto& num : arr1) {
            if (indexMap.find(num) == indexMap.end()) {
                mypairs.push_back({num, 1000 + num});
            } else {
                mypairs.push_back({num, indexMap.at(num)});
            }
        }
        std::sort(mypairs.begin(), mypairs.end(), myobject);
        std::vector<int> result{};
        for (auto& data : mypairs) {
            result.push_back(data.first);
        }
        return result;
    }
};
