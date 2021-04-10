class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		// �п�
		if (m == 0)
			return 0;
		int n = matrix[0].size();

		// ���ٶ�ά���飬��¼֮�󵥵�ջ�Ľ��
		vector<vector<int>> nums(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (matrix[i][j] == '1'){
					// ����һ����Ϊ1
					nums[i][j] = (j == 0 ? 0 : nums[i][j - 1]) + 1;
				}
			}
		}

		// ��ÿһ�н��е���ջ
		int ret = 0;
		for (int j = 0; j < n; ++j){
			// ע�⣺������ǲ��������У�Ҫע�⿪�ٿռ�Ĵ�С
			vector<int> up(m, 0), down(m, 0);
			stack<int> stk;

			// ��һ�е��ϱ߽��¼����
			for (int i = 0; i < m; ++i){
				while (!stk.empty() && nums[stk.top()][j] >= nums[i][j]){
					stk.pop();
				}
				up[i] = stk.empty() ? -1 : stk.top();
				stk.push(i);
			}

			// ��ջ���
			stk = stack<int>();
			// ��һ�е��±߽��¼��down��
			for (int i = m - 1; i >= 0; --i){
				while (!stk.empty() && nums[stk.top()][j] >= nums[i][j]){
					stk.pop();
				}
				down[i] = stk.empty() ? m : stk.top();
				stk.push(i);
			}


			for (int i = 0; i < m; ++i){
				int h = down[i] - up[i] - 1;
				int area = h * nums[i][j];
				ret = max(ret, area);
			}
		}
		return ret;
	}
};