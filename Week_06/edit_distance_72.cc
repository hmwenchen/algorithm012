#include <string>
#include <vector>
#include <algorithm>


class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size(), n = word2.size();
        std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));
        for (int col = 1; col <= n; ++col) {
            dp[0][col] = col;
        }
        for (int row = 1; row <= m; ++row) {
            dp[row][0] = row;
        }
        for (int row = 1; row <= m; ++row) {
            for (int col = 1; col <= n; ++col) {
                if (word1[row - 1] == word2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1];
                } else {
                    dp[row][col] = std::min({dp[row - 1][col], dp[row][col - 1], dp[row - 1][col - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};