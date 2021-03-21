// ������Ӵ�
#include <iostream>
using namespace std;
#include <string>

bool Palindrome(string s)
{
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		++i, --j;
	}
	if (i >= j)
		return true;
	else
		return false;
}

string longestPalindrome(string s) {
	int len = s.size();
	string result = "";
	for (int i = 0; i < len; ++i)
	{
		int j = 1;
		while (i + j <= len)
		{
			string temp = s.substr(i, j);
			if (Palindrome(temp))
			{
				if (temp.size() > result.size())
				{
					result = temp;
				}
			}
			++j;
		}
	}
	return result;
}


int main()
{
	string s = "bb";
	cout << longestPalindrome(s) << endl;
	//cout << Palindrome("bab") << endl;
	return 0;
}

#if 0
// ������
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

#endif