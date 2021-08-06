#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>

// 1����ϣ��
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> freq;
		for (int num : nums) {
			++freq[num];
		}
		int ans = 0;
		for (auto [num, occ] : freq) {
			if (occ == 1) {
				ans = num;
				break;
			}
		}
		return ans;
	}
};

// 2������ȷ��ÿһ��������λ
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < 32; ++i) {
			int total = 0;
			for (int num : nums) {
				total += ((num >> i) & 1);
			}
			if (total % 3) {
				ans |= (1 << i);
			}
		}
		return ans;
	}
};


// 3�����ֵ�·�߼�
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int a = 0, b = 0;
		for (int num : nums) {
			b = ~a & (b ^ num);
			a = ~b & (a ^ num);
		}
		return b;
	}
};



