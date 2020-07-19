
#include <string>
#include <unordered_map>


class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> wordCount{};
        for (auto& character : s) {
            wordCount[character]++;
        }
        for (auto& character : t) {
            if (wordCount.find(character) == wordCount.end()) {
                return false;
            }
            wordCount[character]--;
        }
        for (auto& iter : wordCount) {
            if (iter.second != 0) {
                return false;
            }
        }
        return true;
    }

};


