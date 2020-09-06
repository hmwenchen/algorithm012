#include <string>


class Solution {
public:
    std::string reverseOnlyLetters(std::string S) {
        int left = 0, right = S.size() - 1, n = S.size() - 1;
        while (left < right) {
            while (left < n && !isalpha(S[left])) {
                left++;
            }
            while (right >= 0 && !isalpha(S[right])) {
                right--;
            }
            if (left < right) {
                char temp = S[left];
                S[left++] = S[right];
                S[right--] = temp;
            }
        }
        return S;
    }
};