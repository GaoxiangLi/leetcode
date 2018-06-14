/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//迭代
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
		for(ListNode *prev=head, *cur=head->next; cur!=nullptr;cur=prev->next){
			if(prev->val==cur->val){
				prev->next=cur->next;
				delete cur;
			}else{
				prev=cur;
			}
		}
		return head;
    }
};

class Solution {//递归
	public:
	ListNode *deleteDuplicates(ListNode *head) {
	if (!head) return head;
	ListNode dummy(head->val + 1); // 
	dummy.next = head;
	recur(&dummy, head);
	return dummy.next;
	}
	private:
	static void recur(ListNode *prev, ListNode *cur) {
	if (cur == nullptr) return;
	if (prev->val == cur->val) { //
		prev->next = cur->next;
		delete cur;
		recur(prev, prev->next);
	} else {
		recur(prev->next, cur->next);
	} 
	}
};
}