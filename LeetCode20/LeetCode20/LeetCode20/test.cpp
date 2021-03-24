class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == "(" || s[i] == "[" || s[i] == "{")
			{
				st.push(s[i]);
			}
			else
			{
				if (st.empty())
					return false;


				if (s[i] == ')')
				{
					if (st.top() != '(')
						return false;
					st.pop();
				}
				else if (s[i] == '}')
				{
					if (st.top() != '{')
						return false;
					st.pop();
				}
				else
				{
					if (st.top() != '[')
						return false;
					st.pop();
				}

			}
		}
		return s.empty();
	}
};