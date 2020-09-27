class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		// ���鲻��Ϊ��
		if (matrix.size() == 0)
			return false;
		// i��ʾ�У�j��ʾ�У������һ�п�ʼ
		int i = 0;
		int j = matrix[0].size() - 1;
		// �������target�򷵻�true������target��j--������i++
		while (j >= 0 && i < matrix.size())
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				j--;
			else
				i++;
		}
		return false;
	}
};
