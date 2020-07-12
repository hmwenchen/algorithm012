
#include <vector>
#include <iostream>


class Solution {
public:
    int removeDuplicates_1(std::vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int prev = nums[0];
		int size = 1;
		for (int i = 1; i < nums.size(); ) {
			while (i < nums.size() && prev == nums[i]) {
				i++;
			}
			if (i == nums.size()) {
				return size;
			}
			prev = nums[i];
			nums[size++] = nums[i++];
		}
		return size;
	}

    int removeDuplicates(std::vector<int>& nums) {
    	if (nums.empty()) {
    		return 0;
    	}
    	if (nums.size() == 1) {
    		return 1;
    	}
        int prev = 0;
        int curr = 1;
        while (curr < nums.size()) {
        	if (nums.at(prev) != nums.at(curr)) {
        		nums[++prev] = nums.at(curr);
        	}
        	curr++;
        }
        return ++prev;
    }
};

int main() {
	// std::vector<int> nums{1, 1, 2};
	std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};
	Solution solution;
	int result = solution.removeDuplicates(nums);
	std::cout << "Final length: " << result << std::endl;
	for (auto& n : nums) {
		std::cout << n << std::endl;
	}
}


