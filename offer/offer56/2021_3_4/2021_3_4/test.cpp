class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int n = 0;
		// n��x^y��ֵ
		for (auto num : nums)
			n ^= num;
		// ѭ�����ƣ�����m
		int m = 1;
		while ((n & m) == 0)
			m <<= 1;
		// �������
		int x = 0, y = 0;
		for (auto num : nums)
		{
			if (num & m)
				x ^= num;
			else
				y ^= num;
		}
		return vector<int> {x, y}; // ���س���һ�ε�����
	}
};