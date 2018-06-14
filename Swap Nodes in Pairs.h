class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
			return head;
		}
		ListNode*dummy=new ListNode(-1);
		ListNode*prev=dummy;
		dummy->next=head;
		
		while(prev->next!=NULL&&prev->next->next!=NULL){
			ListNode*tmp=prev->next->next;
			prev->next->next=tmp->next;
			tmp->next=prev->next;
			prev->next=tmp;
			prev=tmp->next;
		}
		return dummy.next;
    }
};

class Solution {//递归算法
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *t = head->next;
        head->next = swapPairs(head->next->next); //直写出交换前两个节点 后面的扔去递归运行
        t->next = head;
        return t;
    }
};