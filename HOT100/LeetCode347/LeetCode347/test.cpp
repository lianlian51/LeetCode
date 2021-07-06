#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

//
//vector<int> topKFrequent(vector<int>& nums, int k) {
//	priority_queue<pair<int, int>, vector<pair<int, int>, less<int>>> pq;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		pq.push(make_pair(nums[i], nums[i]++));
//	}
//	int len = pq.size();
//	cout << len << endl;
//	for (int i = len; i > k; --i)
//		pq.pop();
//	vector<int> ret;
//	for (int i = 0; i < (int)pq.size(); ++i)
//	{
//		ret.push_back(pq.top());
//		cout << pq.top() << endl;
//		pq.pop();
//	}
//	return ret;
//}
//
//int main()
//{
//	vector<int> num{ 1, 1, 1, 2, 2, 3 };
//	topKFrequent(num, 2);
//	return 0;
//}

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		// ����unordered_map��������ֵĸ���
		unordered_map<int, int> m;
		for (auto e : nums)
		{
			m[e]++;
		}

		// ��m�е��������򣬱�֤��������
		multimap<int, int, greater<int>> mm;
		for (auto e : m)
		{
			mm.insert(make_pair(e.second, e.first));
		}
		// ��mm������������ַ�������k��
		vector<int> ret;
		for (auto e : mm)
		{
			if (k == 0)
				break;
			ret.push_back(e.second);
			k--;
		}
		return ret;
	}
};