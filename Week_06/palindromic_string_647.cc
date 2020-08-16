#include <string>
#include <vector>
#include <utility>


class Solution {
public:
    int countSubstrings(std::string s) {
        if (s.empty()) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            extendPalindrom(s, i, i, &result);
            extendPalindrom(s, i, i + 1, &result);
        }
        return result;
    }

private:
    void extendPalindrom(std::string& s, int left, int right, int* result) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            (*result)++;
        }
    }
};