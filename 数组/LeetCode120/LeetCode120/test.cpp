#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <algorithm>

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> dp(triangle.back());
		for (int i = triangle.size() - 2; i >= 0; --i){
			for (int j = 0; j <= i; ++j){
				dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
			}
		}
		return dp[0];
	}
};


// ������
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		// ��̬�滮
		int n = triangle.size();
		vector<vector<int>> f(n, vector<int>(n));
		f[0][0] = triangle[0][0];
		for (int i = 1; i < n; ++i){
			// ��ֵÿ�е�һ��Ԫ��
			f[i][0] = f[i - 1][0] + triangle[i][0];
			for (int j = 1; j < i; ++j){
				// ��ֵÿ���м��Ԫ��
				f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
			}
			// ��ֵÿ�����һ��Ԫ��
			f[i][i] = f[i - 1][i - 1] + triangle[i][i];
		}
		// �������һ����С��Ԫ��
		return *min_element(f[n - 1].begin(), f[n - 1].end());
	}
};