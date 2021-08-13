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
	void reorderList(ListNode* head) {
		vector<ListNode*> vec;
		ListNode* cur = head;
		while (cur != nullptr){
			vec.push_back(cur);
			cur = cur->next;
		}
		int i = 0, j = vec.size() - 1;
		while (i < j)
		{
			vec[i]->next = vec[j];
			i++;
			if (i == j){
				break;
			}
			vec[j]->next = vec[i];
			j--;
		}
		// �ÿ�
		vec[i]->next = nullptr;
	}
};/**
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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* cur = head;
        while(cur != nullptr){
            vec.push_back(cur);
            cur = cur->next;
        }
        int i = 0, j = vec.size() - 1;
        while(i < j)
        {
            vec[i]->next = vec[j];
            i++;
            if(i == j){
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        // �ÿ�
        vec[i]->next = nullptr;
    }
};