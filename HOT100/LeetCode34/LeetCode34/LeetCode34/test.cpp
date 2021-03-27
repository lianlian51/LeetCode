class Solution {
public:
	int leftBound(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (right + left) / 2;
			if (nums[mid] == target)
				right = mid - 1;
			else if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] >target)
				right = mid - 1;
		}
		if (left >= nums.size() || nums[left] != target)
			return -1;
		return left;
	}

	int rightBound(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (right + left) / 2;
			if (nums[mid] == target)
				left = mid + 1;
			else if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid - 1;
		}
		if (right < 0 || nums[right] != target)
			return -1;
		return right;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int left = leftBound(nums, target);
		int right = rightBound(nums, target);
		return{ left, right };
	}
};