//Remove Nth Node From End of List
//删除从右边数的第N个节点，设置两个快慢指针， 快指针先走n，然后快慢指针一起走 当快指针到头时慢指针下一个指向即为被删除的节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(head == NULL || head->next == NULL)  return NULL;  
        ListNode*p=head;
		ListNode*q=head;
		for(int i=0;i<n;i++){
			p=p->next;
		}
		if(p==NULL){
			return head->next;
		}
		while(p->next){
			p=p->next;
			q=q->next;
		}
		ListNode*tmp=q->next;
		q->next=q->next->next;
		delete tmp;
		return head;
    }
};