class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		// �������ұ߽��ֵ
		vector<int> left(n), right(n, n);

		stack<int> mono_stack;
		for (int i = 0; i < n; ++i)
		{
			while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
			{
				right[mono_stack.top()] = i;
				mono_stack.pop();
			}
			// ������������������ֱ�ӽ�ջ����Ϊ�ڱ�
			// ��������ֱ�ӽ�i��top�������topһ����i��ǰһ��λ�ã���������Ҫ��ջ
			left[i] = mono_stack.empty() ? -1 : mono_stack.top();
			mono_stack.push(i);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			// ������ֵ
			ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
		}
		return ans;
	}
};