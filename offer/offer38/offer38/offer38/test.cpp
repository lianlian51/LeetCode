// ����һ���ַ�������ӡ�����ַ������ַ����������С�

// �����������˳�򷵻�����ַ������飬�����治�����ظ�Ԫ�ء�

#include <iostream>
using namespace std;
#include <string>
#include <set>
#include <vector>

void BackTrace(string s, set<string>& res, int start)
{
	if (start == s.size())
	{
		res.insert(s);
		return;
	}
	for (int i = start; i < s.size(); i++)
	{
		// ������ʽ
		swap(s[i], s[start]);
		BackTrace(s, res, start + 1);
		swap(s[i], s[start]);
	}
}

vector<string> permutation(string s)
{
	// ȥ�ش���
	set<string> res;
	BackTrace(s, res, 0);
	return vector<string>(res.begin(), res.end());
}

int main()
{
	string s("abc");
	vector<string> v;
	v = permutation(s);
	for (auto & e : v)
		cout << e << endl;
	return 0;
}