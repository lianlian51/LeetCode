class Solution {
public:
	int search(vector<int>& nums, int target) {
		// �����������
		if (nums.empty())
			return -1;
		if (nums.size() == 1)
			return nums[0] == target ? 0 : -1;

		int left = 0;
		int right = nums.size() - 1;

		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
				return mid;
			// ������ĵط�������
			if (nums[0] <= nums[mid])
			{
				// �����������������ڣ���ô�͸ı�right������ı�left
				if (nums[0] <= target && target < nums[mid])
				{
					right = mid - 1;
				}
				else
					left = mid + 1;
			}
			else
			{
				if (target <= nums[nums.size() - 1] && target > nums[mid])
				{
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
		}
		return -1;
	}
};