///**
//* Definition for a binary tree node.
//* struct TreeNode {
//*     int val;
//*     TreeNode *left;
//*     TreeNode *right;
//*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//* };
//*/
//class Solution {
//public:
//	unordered_map<int, int> index;
//	int idx;
//
//	TreeNode* mybuildTree(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right)
//	{
//		if (in_left > in_right){
//			return nullptr;
//		}
//		// ��ȡ�ڵ��ֵ
//		int root_val = postorder[idx];
//		// ��ȡֵ�������е��±�
//		int in_index = index[root_val];
//		idx--; // �±��-
//		TreeNode* root = new TreeNode(root_val);
//		root->right = mybuildTree(inorder, postorder, in_index + 1, in_right);  // ����������
//		root->left = mybuildTree(inorder, postorder, in_left, in_index - 1);    // ����������
//		return root;
//	}
//
//	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//		int n = inorder.size();
//		idx = n - 1;
//		for (int i = 0; i < n; ++i){ // ��ֵ���±�����ķ�ʽд�뵽��ϣ����
//			index[inorder[i]] = i;
//		}
//		return mybuildTree(inorder, postorder, 0, n - 1);
//	}
//};


//#include <iostream>
//using namespace std;
//#include <string>
//#include <vector>
//
//int main()
//{
//	string s;
//	while (getline(cin, s)){
//		vector<int> vec;
//		int k;
//		for (int i = 0; i < s.size(); ++i){
//			if (s[i] >= '0' && s[i] <= '9'){
//				int temp = 0;
//				while (s[i] >= '0' && s[i] <= '9'){
//					temp = temp * 10 + (s[i] - '0');
//					++i;
//				}
//				vec.push_back(temp);
//			}
//			if (s[i] == ':'){
//				++i;
//				int temp = 0;
//				while (s[i] >= '0' && s[i] <= '9'){
//					temp = temp * 10 + (s[i] - '0');
//					++i;
//				}
//				k = temp;
//			}
//		}
//		int n = vec.size();
//		double p = 0.0;
//		vector<double> avg;
//		for (int i = 0; i < n - k + 1; ++i){
//			double sum = 0.0;
//			for (int j = 0; j < k; ++j){
//				sum += vec[i + j];
//			}
//			sum = sum / (k * 1.0);
//			avg.push_back(sum);
//			if (i > 0){// ����p
//				double tp = (avg[i] - avg[i - 1]) / avg[i - 1];
//				if (tp > p){
//					p = tp;
//				}
//			}
//		}
//		p *= 100;
//		printf("%5.2f%\n", p);
//	}
//
//	return 0;
//}

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
	string s;
	while (getline(cin, s)){
		vector<int> vec;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] >= '0' && s[i] <= '9'){
				int temp = 0;
				while (s[i] >= '0' && s[i] <= '9'){
					temp = temp * 10 + (s[i] - '0');
					++i;
				}
				vec.push_back(temp);
			}
		}
		int n = vec.size();
		unordered_map<int, int> m;
		for (auto& e : vec){
			m[e]++;
		}
		int zero = m[0];
		int k = 0;
		for (auto& e : m){
			if (e.first == 0){
				continue;
			}
			++k;
		}
		if (k > zero){
			std::cout << "[]" << std::endl;
		}
		else {
			vector<int> flag(n, 0);
			for (int i = 0; i < n; ++i){
				if (vec[i] == 0 && !flag[i]){
					int k = i - 1;
					while (flag[k]){
						k--;
					}
					vec[i] = vec[k];
					vec[k] = -1;
					flag[i] = flag[k] = 1;
				}
			}
			for (int i = 0; i < n; ++i){
				if (vec[i] > 0 && !flag[i]){
					vec[i] = -1;
				}
			}
			// ��ӡ
			std::cout << "[";
			int i;
			for (i = 0; i < n - 1; ++i){
				std::cout << vec[i] << ",";
			}
			std::cout << vec[i] << "]" << std::endl;
		}
	}
	return 0;
}