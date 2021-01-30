// ����һ���������飬�����е�һ������������������һ�������顣������������ĺ͵����ֵ��

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int maxSum = nums[0];

		for (int i = 1; i < n; ++i)
		{
			if (nums[i - 1] > 0)
			{
				nums[i] += nums[i - 1];
			}
			maxSum = max(maxSum, nums[i]);
		}
		return maxSum;
	}
};