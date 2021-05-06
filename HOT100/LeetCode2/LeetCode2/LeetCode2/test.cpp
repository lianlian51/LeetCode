
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int ntake = 0;
		ListNode* head = nullptr, *tail = nullptr;
		while (l1 || l2)
		{
			// ������l1����l2�����ڵ����
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + ntake;
			if (!head)
			{
				// ��һ���ڵ���Ҫ��head��tail��ֵ
				head = tail = new ListNode(sum % 10);
			}
			else
			{
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			// ��¼��λ������ֱ�ӳ�10����Ҫֱ�Ӹ�ֵ
			ntake = sum / 10;
			// ��l1����l2������
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		// ������λ
		if (ntake > 0)
			tail->next = new ListNode(ntake);
		return head;
	}
};