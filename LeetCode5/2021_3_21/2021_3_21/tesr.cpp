// ������Ӵ�
class Solution {
public:
	// �����Ŀ�ʼ�������������Ļ��ĳ���
	int center(string s, int left, int right)
	{
		int l = left;
		int r = right;
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			--l, ++r;
		}
		return r - l - 1;
	}

	string longestPalindrome(string s) {
		if (s.size() < 1)
			return "";

		int start = 0;
		int end = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			int len1 = center(s, i, i); // һ��Ϊ���ĵ�
			int len2 = center(s, i, i + 1); // �����ַ�Ϊ���ĵ�
			int len = max(len1, len2);  // �Ƚϳ��ȣ�Ȼ����³���
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		string res = s.substr(start, end - start + 1);
		return res;
	}
};