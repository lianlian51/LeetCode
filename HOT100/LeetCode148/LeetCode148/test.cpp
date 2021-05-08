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
	ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}

	ListNode* sortList(ListNode* head, ListNode* tail)
	{
		if (head == nullptr)
			return head;
		// ������ֿ�
		if (head->next == tail)
		{
			head->next = nullptr;
			return head;
		}

		// ����ָ���ҳ�������м�λ��
		ListNode* fast = head, *slow = head;
		while (fast != tail)
		{
			fast = fast->next;
			slow = slow->next;
			if (fast != tail)
			{
				fast = fast->next;
			}
		}

		ListNode* mid = slow;
		return merge(sortList(head, mid), sortList(mid, tail));
	}

	ListNode* merge(ListNode* head1, ListNode* head2)
	{
		// temp�����������
		ListNode* dummyHead = new ListNode(0);
		ListNode* temp = dummyHead;
		ListNode* temp1 = head1, *temp2 = head2;
		while (temp1 != nullptr && temp2 != nullptr)
		{
			// ��С������temp->next
			if (temp1->val <= temp2->val)
			{
				temp->next = temp1;
				temp1 = temp1->next;
			}
			else
			{
				temp->next = temp2;
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		// ���temp1����temp2���ڵĻ������ӵ�temp֮��
		if (temp1 != nullptr)
			temp->next = temp1;
		if (temp2 != nullptr)
			temp->next = temp2;
		// ����������������
		return dummyHead->next;
	}
};