// ��ָ Offer 45. �������ų���С����
// ����һ���Ǹ��������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����

class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> strs;  // ���ｫԭ��������ת�����ַ���
		string ret;           // ���������ַ���
		for (auto e : nums)
			strs.push_back(to_string(e));

		sort(strs.begin(), strs.end(), cmp);

		for (auto e : strs)
			ret += e;

		return ret;
	}


	// bool�������Ƿ�Ҫ����
	static bool cmp(const string& a, const string& b)
	{
		return a + b < b + a;
	}
};