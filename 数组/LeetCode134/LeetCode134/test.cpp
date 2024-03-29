class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int i = 0;
		while (i < n){
			int sumOfGas = 0, sumOfCost = 0;
			int cnt = 0;
			while (cnt < n){ // cnt表示访问次数，在i的基础上加，这样就可以全部访问所有的数字
				int j = (cnt + i) % n;
				sumOfCost += cost[j];
				sumOfGas += gas[j];
				if (sumOfCost > sumOfGas){ // 花费比拥有多直接break
					break;
				}
				++cnt;
			}
			if (cnt == n){ // 如果此时相等，说明已经访问了n次
				return i;
			}
			else {
				i = i + cnt + 1; // 反之i+cnt前面都不能满足条件
			}
		}
		return -1;
	}
};