class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		std::vector<int> ret;
		priority_queue<std::pair<int, int>> q;
		for (int i = 0; i < k; ++i)
		{
			q.emplace(nums[i], i);
		}

		ret.push_back(q.top().first);
		for (int i = k; i < n; ++i)
		{
			q.emplace(nums[i], i);
			// ��Ϊÿ��i++��Ե�ʣ����������ж�С�ڵ���i-k�����޳�
			while (!q.empty() && q.top().second <= i - k)
				q.pop();

			ret.push_back(q.top().first);
		}
		return ret;
	}
};