class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int maxPos = 0, end = 0, step = 0;

		for (int i = 0; i < n - 1; ++i){
			if (maxPos >= i){ // maxPos�±��������ʾÿ���߹���λ�õ��±�
				maxPos = max(maxPos, i + nums[i]);
				if (i == end){ // end��ʾ��һ��maxPos��λ�ã���i==endʱ����ʾi���ߵ���һ��maxPos�߹���λ�ã�����end��λ�ã�step+1
					end = maxPos;
					++step;
				}
			}
		}
		return step;
	}
};