class Solution {
public:
	vector<int> t;
	vector<vector<int>> res;

	vector<vector<int>> subsets(vector<int>& nums) {
		int len = nums.size();
		// �����mask��ÿ�μ�1������������Ϊ��
		// 000 �����������뵽res
		// 001,010,100  ��һ��������������
		// 011,101,110  ��������������res
		// 111 ��������������res
		for (int mask = 0; mask < (1 << len); ++mask)
		{
			t.clear();
			for (int i = 0; i < len; ++i)
			{
				// ֻҪ��λ����ڵĻ����ͽ���Ӧ��nums[i]������ʱt�У�������֮���������뵽res��
				if (mask & (1 << i))
				{
					t.push_back(nums[i]);
				}
			}
			res.push_back(t);
		}
		return res;
	}
};