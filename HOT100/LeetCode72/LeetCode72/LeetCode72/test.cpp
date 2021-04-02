class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();

		// �ж��������
		if (m * n == 0)
			return m + n;

		int nums[m + 1][n + 1];
		// �߽��ʼ��
		for (int i = 0; i < m + 1; i++)
		{
			nums[i][0] = i;
		}
		for (int j = 0; j < n + 1; ++j)
		{
			nums[0][j] = j;
		}

		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 1; j < n + 1; ++j)
			{
				// �ֱ��ʾ��ǰ���ֵ���һ��λ�ã���ߵ�λ�ã����ϵ�λ�ò���һ�εĽ��
				// �������ϵ�λ�ã���ʾ�ַ������Ĳ��������������˳��Ļ����Ͳ��ý��������򽻻�
				// ��߱�ʾword2�Ĳ����ɾ�����ϱ߶�word1�Ĳ����ɾ��
				int up = nums[i - 1][j] + 1;
				int left = nums[i][j - 1] + 1;
				int left_up = nums[i - 1][j - 1];

				if (word1[i - 1] != word2[j - 1])
					left_up += 1;
				nums[i][j] = min(left, min(left_up, up));
			}
		}
		return nums[m][n];
	}
};