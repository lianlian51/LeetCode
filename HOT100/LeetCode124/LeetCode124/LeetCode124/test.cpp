/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
	int sum = INT_MIN;
public:
	int maxvalue(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		// ������������ļ�ֵ
		int left = max(maxvalue(root->left), 0);
		int right = max(maxvalue(root->right), 0);

		// �������ֵ
		int price = left + right + root->val;

		// ���¼�ֵ
		sum = max(sum, price);

		return root->val + max(left, right);
	}

	int maxPathSum(TreeNode* root) {
		maxvalue(root);
		return sum;
	}
};