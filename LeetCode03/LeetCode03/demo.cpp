// �����㷨
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		// �ȶ������������
		sort(nums.begin(), nums.end());

		// Ȼ�������ڵ������Ƿ���ͬ����ͬ�����أ�
		// ѭ����������û���ҵ��Ļ��ͷ���-1
		for (int i = 0; i < nums.size(); ++i)
		{
			int j = i + 1;
			if (nums[i] == nums[j])
				return nums[i];
		}
		return -1;
	}
};


// ��Ƿ�
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		//����һ��char����
		unsigned char tmp[nums.size()];
		// ������������ַ�ȫ������Ϊ0�������0�ַ��������ĸ��ֽڣ�
		memset(tmp, 0, nums.size());
		for (int i = 0; i < nums.size(); ++i)
		{
			// �������tmp[nums[i]]��1�����ǵ�һ�γ��֣��ͷ���
			if (tmp[nums[i]])
				return nums[i];
			// �ǵ�һ�γ�������Ϊ1
			tmp[nums[i]] = 1;
		}
		return -1;
	}
};
