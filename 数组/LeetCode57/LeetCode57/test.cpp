class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int left = newInterval[0];
		int right = newInterval[1];
		bool placed = false; // ��placed��ʾ���Ҫ���������ֻ�ܲ���һ��
		vector<vector<int>> ans;
		for (const auto interval : intervals){
			if (interval[0] > right){ // �������Ѿ�����Ҫ����ĵط�
				if (!placed){
					ans.push_back({ left, right });
					placed = true; // ��Ҫ��ʱ����
				}
				ans.push_back(interval);
			}
			else if (interval[1] < left){ // �����ǻ�û��Ҫ����ĵط�
				ans.push_back(interval);
			}
			else {
				// ����������ǽ���
				left = min(left, interval[0]);
				right = max(right, interval[1]);
			}
		}
		if (!placed){
			ans.push_back({ left, right });
		}
		return ans;
		// ���ֲ��ÿ�����ô����ÿ�������left��right������ֻ�ÿ��Ը���left��right��ֵ�����û�в����ʱ�򣬽�������ȥ
	}
};