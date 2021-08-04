class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int i = 0;
		while (i < n){
			int sumOfGas = 0, sumOfCost = 0;
			int cnt = 0;
			while (cnt < n){ // cnt��ʾ���ʴ�������i�Ļ����ϼӣ������Ϳ���ȫ���������е�����
				int j = (cnt + i) % n;
				sumOfCost += cost[j];
				sumOfGas += gas[j];
				if (sumOfCost > sumOfGas){ // ���ѱ�ӵ�ж�ֱ��break
					break;
				}
				++cnt;
			}
			if (cnt == n){ // �����ʱ��ȣ�˵���Ѿ�������n��
				return i;
			}
			else {
				i = i + cnt + 1; // ��֮i+cntǰ�涼������������
			}
		}
		return -1;
	}
};