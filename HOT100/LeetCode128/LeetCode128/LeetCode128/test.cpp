class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		// ���ù�ϣ��unordered_set��ȥ�صĹ���
		unordered_set<int> nums_set;
		for (auto& num : nums)
			nums_set.insert(num);

		// ����ֵ
		int longret = 0;
		for (auto& num : nums_set)
		{
			// ���num- 1���ڵĻ�����ôֱ�����������Լ������д���
			if (!nums_set.count(num - 1))
			{
				// curnum��ʾ����������
				// curlen ��ʾ�������ֵĳ���
				int curnum = num;
				int curlen = 1;
				while (nums_set.count(curnum + 1))
				{
					curnum += 1;
					curlen += 1;
				}
				// ���³���
				longret = max(longret, curlen);
			}
		}
		return longret;
	}
};