// ������
// write your code here cpp
#include <iostream>
using namespace std;
#include <vector>
#include <string>

// �ں�����Ҫ��string s[]�ķ�ʽ
bool func(string  s[])
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			int right = 1, right_down = 1, down = 1, left_down = 1;
			for (int t = 1; t < 5; t++)
			{
				// ���� . ��ֱ������
				// �����ǰ��廹�Ǻ��壬���ǵ��ַ�����ȣ������������������
				// ��t����������
				if (s[i][j] == '.')
					continue;
				if (j < 16 && s[i][j] == s[i][j + t])
					right++;
				if (i < 16 && j < 16 && s[i][j] == s[i + t][j + t])
					right_down++;
				if (i < 16 && s[i][j] == s[i + t][j])
					down++;
				if (j > 4 && i < 16 && s[i][j] == s[i + t][j - t])
					left_down++;
			}
			if (right == 5 || right_down == 5 || down == 5 || left_down == 5)
				return true;
		}
	}
	return false;
}

int main()
{
	string s[20];  // ����һ��20�е��ַ���
	while (cin >> s[0])
	{
		// ��ÿһ�ж������ַ�
		for (int i = 1; i < 20; ++i)
			cin >> s[i];

		cout << (func(s) ? "Yes" : "No") << endl;
	}
	return 0;
}
