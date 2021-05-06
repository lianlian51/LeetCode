class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// �������е��ַ��������Ƿ��ظ�
		unordered_set<char> s_set;
		int len = s.size();

		int rk = -1;
		int ans = 0;
		for (int i = 0; i < len; ++i)
		{
			// �����ƶ���ʱ��Ҫ��s_set�и�λ�õ��ַ�ȥ��
			if (i != 0)
			{
				s_set.erase(s[i - 1]);
			}
			// �����λ���ַ�������s_set�У����������Ѱ��
			while (rk + 1 < len && !s_set.count(s[rk + 1]))
			{
				s_set.insert(s[rk + 1]);
				++rk;
			}
			// ����ans
			ans = max(ans, rk - i + 1);
		}
		return ans;
	}
};