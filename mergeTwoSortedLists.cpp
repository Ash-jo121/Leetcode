class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode *l3 = NULL;
		l3 = new ListNode();
		while (l1 != NULL || l2 != NULL) {
			if (l1->val >= l2->val) {
				ListNode p = new ListNode();
				p->next = NULL;
				l3->next = p;
				l3 = l3->next;
				l3->val = l1->val;
				l2 = l2->next;
			}
			else {
				ListNode p = new ListNode();
				p->next = NULL;
				l3->next = p;
				l3 = l3->next;
				l3->val = l1->val;
				l1 = l1->next;
			}
		}
		if (l2 != NULL) {
			while (l2 != NULL) {
				ListNode p = new ListNode();
				p->next = NULL;
				l3->next = p;
				l3 = l3->next;
				l3->val = l2->val;
				l2 = l2->next;
			}
		}
		else if (l1 != NULL) {
			while (l1 != NULL) {
				ListNode p = new ListNode();
				p->next = NULL;
				l3->next = p;
				l3 = l3->next;
				l3->val = l1->val;
				l1 = l1->next;
			}
		}
		return l3;

	}
}