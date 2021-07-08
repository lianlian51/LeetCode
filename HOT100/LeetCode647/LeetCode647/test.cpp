#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

	int countSubstrings(string s) {
		// manacher�㷨
		int n = s.size();
		// mach�洢����#���ַ�����maxR������ÿ���±�Ϊ���ĵ��ƥ��뾶
		string mach = "$#";
		
		for (const char& c : s)
		{
			mach += c;
			mach += '#';
		}
		n = mach.size();
		mach += '!';
		cout << n << endl;
		auto maxR = vector<int>(n);
		int R = 0, C = 0;
		int ans = 0;
		for (int i = 1; i < n; ++i)
		{
			// ��һ��������̵Ļ��İ뾶
			maxR[i] = (i <= R) ? min(R - i + 1, maxR[2 * C - i]) : 1;
			// �������
			while (mach[i + maxR[i]] == mach[i - maxR[i]])
			{
				++maxR[i];
			}
			// ����R��C
			if (i + maxR[i] - 1 > R)
			{
				R = i + maxR[i] - 1;
				C = i;
			}
			ans += (maxR[i] / 2);
		}
		return ans;
	}


	int main()
	{
		cout << countSubstrings("abc") << endl;
		return 0;
	}