//class Solution {
//public:
//	vector<int> dailyTemperatures(vector<int>& temperatures) {
//		int n = temperatures.size();
//		std::vector<int> vec(n, 0);
//		stack<int> s;
//		for (int i = 0; i < n; ++i)
//		{
//			while (!s.empty() && temperatures[i] > temperatures[s.top()])
//			{
//				int top = s.top();
//				vec[top] = i - top;
//				s.pop();
//			}
//			s.push(i);
//		}
//		return vec;
//	}
//};

