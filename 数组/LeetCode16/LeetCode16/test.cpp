class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		// ����+˫ָ��
		sort(nums.begin(), nums.end());

		int n = nums.size();
		int best = 1e7;
		// ����lambda���ʽ������ӽ�������
		auto update = [&](int cur){
			if (abs(cur - target) < abs(best - target))
			{
				best = cur;
			}
		};

		for (int i = 0; i < n; ++i)
		{
			// ��ʱ����ö�٣���֤��κ��´εĲ�һ��
			if (i > 0 && nums[i] == nums[i - 1]){
				continue;
			}
			int j = i + 1;
			int k = n - 1;
			// ˫ָ������ҵ�����ʵ�����
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				// �����target����ô������ӽ�������
				if (sum == target){
					return sum;
				}
				update(sum);
				if (sum > target)
				{
					int k0 = k - 1;
					// ������ͬ�����֣��������һ����ע�⴦��ʱ��ֹԽ��
					while (j < k0 && nums[k0] == nums[k])
						--k0;

					k = k0;
				}
				else {
					int j0 = j + 1;
					while (j0 < k && nums[j0] == nums[j]){
						++j0;
					}
					j = j0;
				}
			}
		}
		return best;
	}
};