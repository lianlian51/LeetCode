class Solution {
public:
	int findNthDigit(int n) {
		if (n == 0)
			return 0;
		int digit = 1; // ��λ
		long start = 1; // ���ڸ���λ������������ʼ����
		long index_count = digit * 9 * start; // ����λ�е�һ���ж��ٸ���������
		while (n > index_count)
		{
			n -= index_count;
			++digit;
			start *= 10;
			index_count = digit * 9 * start;
		}

		long num = start + (n - 1) / digit; // ���ԭʼ��n���׶�Ӧ�Ǹ�����
		int remainder = (n - 1) % digit; // ��������ԭʼ��n����������еĵڼ�λ
		string s_num = to_string(num);
		return int(s_num[remainder] - '0');
	}
};