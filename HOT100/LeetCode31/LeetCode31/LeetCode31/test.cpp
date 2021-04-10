class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		// 1.��β����ʼ������Ȼ���ҵ����������
		int i = nums.size() - 2;
		while (i >= 0 && nums[i] >= nums[i + 1])
			--i;

		if (i >= 0)
		{
			// 2.�ҵ���һ���ϴ������
			int j = nums.size() - 1;
			while (j >= 0 && nums[i] >= nums[j])
				j--;

			swap(nums[i], nums[j]);
		}
		// 3.��תi֮���������
		reverse(nums.begin() + i + 1, nums.end());
	}
};