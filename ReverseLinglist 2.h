//思路与整个逆序相同 先找到逆序的开始的前一个 在开始逆序
//维护3个指针，p,head,tmp
// p永远指向需要开始reverse的点的前一个位置
//head为逆序后的队尾 tmp指向head后一个 
//先将head指向tmp的后一个 再把tmp插进队头

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
     public:ListNode *reverseBetween(ListNode *head, int m, int n)   
    {  
        ListNode dummy(0);  
        ListNode *p = &dummy;  
        dummy.next = head;  
  
        for (int i = 1; i < m; i++) p = p->next;  
        head = p->next;  
  
        for ( ; m < n; m++)  
        {  
            ListNode *tmp = head->next;  
            head->next = tmp->next;  
            tmp->next = p->next;  
            p->next = tmp;  
        }  
        return dummy.next;  
    }  
};