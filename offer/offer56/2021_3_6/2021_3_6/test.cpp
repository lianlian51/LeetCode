class Solution {
public:
	int singleNumber(vector<int>& nums) {
		// ��������ϣ������¼��once��¼һ�ε����֣�
		// twice��ʾ���ڶ�ε����ּ�¼��Ȼ��ɾ��once�еļ�¼�������once�б��ǳ���һ�ε�����
		unordered_set<int> once, twice;
		for (auto num : nums)
		{
			if (once.count(num))
			{
				twice.count(num);
				once.erase(num);
			}
			else if (twice.count(num))
				continue;
			else
				once.insert(num);
		}
		return *once.begin();
	}
};