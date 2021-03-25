/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	struct status
	{
		int val;
		ListNode* ptr;
		bool operator<(const status& down)const
		{
			return val > down.val;
		}
	};

	// ���ȼ����д���
	priority_queue<status> q;

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// 1.����������������뵽���ȼ������У�ÿ���ڵ�֮����һ������
		for (auto e : lists)
		{
			if (e)
				q.push({ e->val, e });
		}

		// 2.head���ͷ����tail�����ߣ������µĽڵ�
		ListNode head, *tail = &head;
		while (!q.empty())
		{
			auto tmp = q.top();
			q.pop();
			// ���������ָ�룬��Ȼ��������
			tail->next = tmp.ptr;
			tail = tail->next;
			// ��Ϊtmp��һ�������������һ���ڵ�֮�󣬻���Ҫ����֮��������ڵ�
			if (tmp.ptr->next)
			{
				q.push({ tmp.ptr->next->val, tmp.ptr->next });
			}
		}

		return head.next;
	}
};