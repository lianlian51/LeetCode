class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		// ˫��Ƿ�
		int m = matrix.size();
		int n = matrix[0].size();
		int fr = false, fc = false;
		// ȷ����һ�к͵�һ���Ƿ���0
		for (int i = 0; i < m; ++i){
			if (!matrix[i][0]){
				fr = true;
			}
		}
		for (int i = 0; i < n; ++i){
			if (!matrix[0][i]){
				fc = true;
			}
		}
		// �����˵�һ�к͵�һ������0��Ԫ�صĸ��к͸��еĵ�һ��Ԫ����Ϊ0
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				if (!matrix[i][j]){
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		// ������л��е�һ��Ԫ��Ϊ0���򽫸�λ����Ϊ0
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				if (!matrix[i][0] || !matrix[0][j]){
					matrix[i][j] = 0;
				}
			}
		}
		// ����ǵ��к�����Ϊ0
		for (int i = 0; i < m; ++i){
			if (fr){
				matrix[i][0] = 0;
			}
		}
		for (int i = 0; i < n; ++i){
			if (fc){
				matrix[0][i] = 0;
			}
		}
	}
};