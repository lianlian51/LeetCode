class Solution {
public:
	int hammingDistance(int x, int y) {
		x = x^y;
		int count = 0;
		while (x)
		{
			if (x & 1)
			{
				count++;
			}
			x >>= 1;
		}
		return count;
	}
};