/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root)
		{
			// ��Ϊ�Ƕ��������������Կ��Ը���ֵ��Ѱ��
			// �ڵ��ֵ����p��q�ģ���ô��������������Ѱ��
			if (root->val > p->val && root->val > q->val)
			{
				root = root->left;
			}
			else if (root->val < p->val && root->val < q->val)
			{
				root = root->right;
			}
			else
			{
				// ����һ����������һ��������������ô�ͷ���root
				return root;
			}
		}
		return NULL;
	}
};