class Solution {
public:
	// �����ּ������
	string getDig(string& s, int& ptr)
	{
		string ret = "";
		while (isdigit(s[ptr]))
		{
			ret += s[ptr++];
		}
		return ret;
	}

	// �������з��ַ���ת��Ϊ�ַ���
	string getString(vector<string> s)
	{
		string ret = "";
		for (auto & e : s)
			ret += e;
		return ret;
	}

	string decodeString(string s) {
		int len = s.size();
		int ptr = 0;
		vector<string> stk;
		while (ptr < len)
		{
			char cur = s[ptr];
			if (isdigit(cur))
			{
				string temp = getDig(s, ptr);
				stk.push_back(temp);
			}
			else if (isalpha(s[ptr]) || s[ptr] == '[')
			{
				stk.push_back(string(1, s[ptr++]));
			}
			else
			{
				++ptr;
				vector<string> temp;
				while (stk.back() != "[")
				{
					temp.push_back(stk.back());
					stk.pop_back();
				}
				reverse(temp.begin(), temp.end());
				// �����ų�ջ
				stk.pop_back();
				string t, o = getString(temp);
				int times = stoi(stk.back());
				// ���ֳ�ջ
				stk.pop_back();
				// ������ַ�����ջ��������������Ϊ�˷�ֹ[]��[]�����
				for (int i = 0; i < times; ++i)
					t += o;
				stk.push_back(t);
			}
		}
		// ���ս�ջ�е�Ԫ�ض�ƴ����������
		return getString(stk);
	}
};