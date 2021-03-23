class Solution {
public:
	map<char, string> Map{
		{ '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }
	};
	// ���淵�ؽ��
	vector<string> result;
	// ��ʱ��
	string temp;

	// index��Ӧÿ�����ְ������ַ��ĸ���
	void DFS(int index, string& digits)
	{
		// index��¼��ʱtmp���ַ��ĸ����������digits����ȣ��ͽ�tempд��result��
		if (digits.size() == index)
		{
			result.push_back(temp);
			return;
		}

		// digits[index]��ʾ�ַ���Map[digits[index]][i]��ʾ�����ַ���Ӧ��Ӣ����ĸ
		for (int i = 0; i < Map[digits[index]].size(); ++i)
		{
			temp.push_back(Map[digits[index]][i]);
			DFS(index + 1, digits);
			temp.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
			return result;
		DFS(0, digits);
		return result;
	}
};
