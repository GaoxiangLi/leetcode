/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //向后遍历K个 如果为空则直接返回 不为空则递归运行 并且排列好前K个
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr|| head->next == nullptr||k<2) return head;
		ListNode*p=head;
		for(int i=0;i<k;i++){
			p=p->next;
			if(p){
			p=p->next;
			}else{
			return head;
			}
		}
		
		
		
    }
};


//遍历整个链表，统计出链表的长度，然后如果长度大于等于k，我们开始交换节点，当k=2时，
//每段我们只需要交换一次，当k=3时，每段需要交换2此，所以i从1开始循环，注意交换一段后更新pre指针，然后num自减k，直到num<k时循环结束，
ass Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr|| head->next == nullptr||k<2) return head;\
		ListNode*dummy=new ListNode(-1);
		dummy->next=head;
		
		ListNode*prev=dummy;
        ListNode*p=prev;
		int length=0;
		while(p->next!=nullptr){
			length++;
			p=p->next;
		}
		while(length>=k){
			p=prev->next;
			for(int i=1;i<k;i++){
			ListNode* tmp=p->next; //prev指向头部当前第一个 p为prev指向 tmp为p下一个 先将p指向tmp的下一个 tmp再指向prev->next成为新的头部即交换了顺序 p->next=tmp prev移动指向新的头部
			p->next=tmp->next;
			tmp->next=prev->next;
			prev->next=tmp;
			}
			prev=p;  //prev始终指向头部
			length=length-k;
		}
		return dummy->next;
		
		
		
		
    }
};