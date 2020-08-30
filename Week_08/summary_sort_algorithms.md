
# sort algorithms

## merge sort

```c++
void mergeSort(vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}
	int middle = left + (right - left) / 2;
	mergeSort(nums, left, middle);
	mergeSort(nums, middle + 1, right);
	merge(nums, left, middle, right);
}

void merge(vector<int>& nums, int left, int middle, int right) {
	int pleft = left, pright = middle + 1, i = 0;
	std::vector<int> temp(right - left + 1, 0);
	while (pleft <= middle && pright <= right) {
		temp[i++] = nums[pleft] <= nums[pright] ? nums[pleft++] : nums[right++];
	}
	while (pleft <= middle) {
		temp[i++] = nums[pleft++];
	}
	while (pright <= right) {
		temp[i++] = nums[right++];
	}
	for (int k = 0; k < temp.size(); ++k) {
		nums[left + k] = temp[k];
	}
}

```


## quick sort

```python

def quick_sort(begin, end, nums):
	if begin >= end:
		return
    pivot = partition(begin, end, nums)
    quick_sort(begin, pivot - 1, nums)
    quick_sort(pivot + 1, end, nums)

def partition(begin, end, nums):
	pivot = nums[begin]
	mark = begin
	for i in range(begin + 1, end + 1):
		if nums[i] < pivot:
			mark += 1
			nums[mark], nums[i] = nums[i], nums[mark]
    nums[mark], nums[begin] = nums[begin], nums[mark]
    return mark

```


## selection sort

```c++

void selectionSort(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[j] < nums[minIndex]) {
				minIndex = j;
			}
		}
		swap(nums[j], nums[minIndex]);
	}
}

```


## insertion sort

```c++

void insertionSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int temp = nums[i];
		for (int j = i; j > 0 && nums[j - 1] > temp; --j) {
			nums[j] = nums[j - 1];
		}
		nums[j] = temp;
	}
}

```





