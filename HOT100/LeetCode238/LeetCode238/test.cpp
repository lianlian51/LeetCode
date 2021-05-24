
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		std::vector<int> ret(n, 1);
		// prefix��¼��ߵĻ���suffix��¼�ұߵĻ�
		int prefix = 1, suffix = 1;
		for (int i = 0; i < n; ++i)
		{
			ret[i] *= prefix;
			ret[n - i - 1] *= suffix;
			prefix *= nums[i];
			suffix *= nums[n - i - 1];
		}
		return ret;
	}
};