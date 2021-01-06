class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		priority_queue<int>pq;
		multiset<int>s;
		map<int, int>m;
		for (int i = 0; i < k; i++) {
			pq.push(nums[i]);
			m[nums[i]]++;
		}
		int max = pq.top();
		int new_var = 0;
		int exit_var = 0;
		vector<int>soln;
		soln.push_back(max);
		for (int i = k; i < nums.size(); i++) {
			new_var = nums[i];
			exit_var = nums[i - k];
			m[new_var]++;
			pq.push(new_var);
			s.insert(exit_var);
			if (new_var >= max) {
				soln.push_back(new_var);
				max = new_var;
			}
			else {
				if (exit_var != max) {
					soln.push_back(max);
				}
				else {
					pq.pop();
					while (s.find(pq.top()) != s.end() && s.count(pq.top()) == m[pq.top()]) {
						pq.pop();
					}
					max = pq.top();
					soln.push_back(max);
				}
			}
		}
		return soln;

	}
};