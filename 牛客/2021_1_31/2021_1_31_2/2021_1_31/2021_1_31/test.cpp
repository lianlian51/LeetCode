// ���Ӹ���
// ���û�����ڵ�set��ֱ��������ͺ�


#include <iostream>
using namespace std;
#include <cmath>

int main()
{
	int n, k;
	while (cin >> n)
	{
		k = 0;
		for (int i = 2; i < sqrt(n); i++)
		{
			if (n % i == 0)
			{
				while (n % i == 0)
					n /= i;
				k++;
			}
		}
		if (n != 1)
			k++;
		cout << k << endl;
	}
	return 0;
}