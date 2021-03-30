class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// ��ֵ��[key, value]
		// ����key����ĸ����֮����ַ��������֮����������ַ�����ȵĻ�����ô�ͷ���ͬһ��vector��
		unordered_map<string, vector<string>> mp;
		for (auto& e : strs)
		{
			// str��ʱֵ�������������ַ�����Ҳ�ǲ���keyֵ
			string str = e;
			sort(str.begin(), str.end());
			mp[str].emplace_back(e);
		}

		// ���ﲻ��auto��ԭ����mp��value����һ�����ͣ�����һ��string���͵�����
		vector<vector<string>> ans;
		for (auto it = mp.begin(); it != mp.end(); ++it)
		{
			ans.emplace_back(it->second);
		}
		return ans;
	}
};