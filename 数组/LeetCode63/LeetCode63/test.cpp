class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		// ��̬�滮
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<int> ret(n);
		ret[0] = (obstacleGrid[0][0] == 0);
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				// �����ϰ���
				if (obstacleGrid[i][j] == 1){
					ret[j] = 0;
					continue;
				}
				// ��֤j-1�Ϸ���obstacleGrid[i][j-1]�Ϸ�
				if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0){
					ret[j] += ret[j - 1];
				}
			}
		}
		return ret.back();
	}
};