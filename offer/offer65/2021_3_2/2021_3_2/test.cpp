class Solution {
public:
	// λ����
	int add(int a, int b) {
		if (a == 0 || b == 0)
		{
			return a == 0 ? b : a;
		}

		int sum = 0, carry = 0;
		while (b != 0)
		{
			sum = a ^ b;
			carry = (unsigned int)(a & b) << 1;  // ���������������Ʋ�����������unsigned int

			a = sum;
			b = carry;
		}

		return a;
	}
};