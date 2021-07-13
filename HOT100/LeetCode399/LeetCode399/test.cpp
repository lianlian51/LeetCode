class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		int nars = 0;
		unordered_map<string, int> ques;
		// ��������в��ظ��ĸ����������洢��ques�е�ֵ��
		int len = equations.size();
		for (int i = 0; i < len; ++i)
		{
			if (ques.find(equations[i][0]) == ques.end()){
				ques[equations[i][0]] = nars++;
			}
			if (ques.find(equations[i][1]) == ques.end()){
				ques[equations[i][1]] = nars++;
			}
		}

		// ���������㷨���Ƚ�ͼ�������������֪�����ֳ������ڶ�ά������
		vector<vector<double>> gragh(nars, vector<double>(nars, -1.0));
		for (int i = 0; i < len; ++i)
		{
			int va = ques[equations[i][0]];
			int vb = ques[equations[i][1]];
			gragh[va][vb] = values[i];
			gragh[vb][va] = 1.0 / values[i];
		}

		// ������ַ������������
		for (int k = 0; k < nars; ++k)
		{
			for (int i = 0; i < nars; ++i)
			{
				for (int j = 0; j < nars; ++j)
				{
					if (gragh[i][k] > 0 && gragh[k][j] > 0)
					{
						gragh[i][j] = gragh[i][k] * gragh[k][j];
					}
				}
			}
		}

		vector<double> ret;
		for (auto & e : queries)
		{
			double result = -1.0;
			if (ques.find(e[0]) != ques.end() && ques.find(e[1]) != ques.end())
			{
				int ia = ques[e[0]], ib = ques[e[1]];
				result = gragh[ia][ib];
			}
			ret.push_back(result);
		}
		return ret;
	}
};