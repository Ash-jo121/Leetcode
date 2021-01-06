class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *l3 = NULL;
		l3 = new ListNode();
		k = lists.size();
		ListNode *head = l3;
		priority_queue<int, vector<int>, greater<int>>pq;
		for (int i = 0; i < k; i++) {
			while (lists[i] != NULL) {
				pq.push(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}
		while (!pq.empty()) {
			ListNode *p = NULL;
			p = new ListNode();
			l3->next = p;
			l3 = l3->next;
			l3->val = pq.top();
			pq.pop();

		}
		l3 = head->next;
		return l3;
	}
};