class Solution {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		// rightmost��ʾ�ұ߿��Դﵽ�������
		int rightmost = 0;
		for (int i = 0; i < len; ++i)
		{
			// �������i����rightmost���������ôһ������false
			if (i <= rightmost)
			{
				rightmost = max(rightmost, i + nums[i]);
				if (rightmost >= len - 1)
					return true;
			}
		}
		return false;
	}
};
