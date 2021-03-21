/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// ������
class Solution {
public:
	vector<int> v;

	void Inorder(TreeNode* root)
	{
		if (root)
		{
			Inorder(root->left);
			v.push_back(root->val);
			Inorder(root->right);
		}
	}

	int kthLargest(TreeNode* root, int k) {
		v.clear();
		Inorder(root);

		return v[v.size() - k];
	}
};

// ��ȱ���
class Solution {
public:
	int res;
	int k;
	int kthLargest(TreeNode* root, int k) {
		this->k = k;
		dfs(root);
		return res;
	}

	void dfs(TreeNode* cur)
	{
		if (cur != nullptr)
		{
			dfs(cur->right);
			if (--k == 0)
			{
				res = cur->val;
				return;
			}
			dfs(cur->left);
		}
	}
};
