#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <iostream>

/**
 * g++ --std=c++11 -o jump_game_ii.o jump_game_II_45.cc
 */

class Solution {
public:
    int jump(std::vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return 0;
        }
        int N = nums.size();
        int minSteps = INT_MAX;
        std::queue<std::vector<int> > myqueue{};
        myqueue.push({0});
        while (!myqueue.empty()) {
            int qsize = myqueue.size();
            for (int i = 0; i < qsize; ++i) {
                std::vector<int> currentRoute = myqueue.front();
                myqueue.pop();
                int lastIndex = currentRoute.back();
                if (lastIndex == nums.size() - 1) {
                    int currentSteps = currentRoute.size() - 1;
                    minSteps = std::min(minSteps, currentSteps);
                    return minSteps;
                }

                int maxReachable = std::min(lastIndex + nums[lastIndex], N - 1);
                for (int nextPosition = maxReachable ;
                        nextPosition >= currentRoute.back() + 1;
                        --nextPosition) {
                    std::vector<int> temp(currentRoute.begin(), currentRoute.end());
                    temp.push_back(nextPosition);
                    myqueue.push(temp);
                }
            }
        }
        return minSteps;
    }

    /**
     * [ref] https://leetcode.com/problems/jump-game-ii/discuss/18019/10-lines-C%2B%2B-(16ms)-Python-BFS-Solutions-with-Explanations
     */
    int jump_2(std::vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return 0;
        }
        int n = nums.size(), start = 0, end = 0, steps = 0;
        while (end < n - 1) {
            steps++;
            int farthest = end + 1;
            for (int i = start; i <= end; ++i) {
                if (i + nums[i] >= n - 1) {
                    return steps;
                }
                farthest = std::max(farthest, i + nums[i]);
            }
            start = end + 1;
            end = farthest;
        }
        return steps;
    }
};


int main() {
    Solution s;
    std::vector<int> nums{6,2,6,1,7,9,3,5,3,7,2,8,9,4,7,7,2,2,8,4,6,6,1,3};
    int result = s.jump(nums);
    std::cout << result << std::endl;
}