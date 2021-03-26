class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;

		int maxLen = 0;
		stack<int> st;  // ջ�зţ����±�
		st.push(-1);   // ��һ������
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				st.push(i);
			}
			else
			{
				// �����ǣ���������ͳ�ջ��Ȼ���ж����ջ�վ�ѹջ�����յĻ����޸�maxLen��ֵ
				st.pop();
				if (st.empty())
					st.push(i);
				else
					maxLen = max(maxLen, i - st.top());  // ��-1��0��1��2��˵�����������������������ţ�Ȼ������һ���������±�3���ͳ�ջһ������-1��0��1������һ���������±����4��maxLen�޸�Ϊ2��ѭ����ջ�գ�������
			}
		}
		return maxLen;
	}
};