class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> vec;
		vector<int> res;
		int limit = (target - 1) / 2;
		int sum = 0;
		// ��1��ʼ�������ֵ��ӣ�ֱ�����
		for (int i = 1; i <= limit; i++)
		{
			for (int j = i;; j++)
			{
				sum += j;
				if (sum > target)
				{
					sum = 0;
					break;
				}
				else if (sum == target)
				{
					// ����֮ǰ�Ĵ洢������
					res.clear();
					for (int k = i; k <= j; k++)
					{
						res.emplace_back(k);
					}
					vec.emplace_back(res);
					sum = 0;
					break;
				}
			}
		}
		return vec;
	}
};