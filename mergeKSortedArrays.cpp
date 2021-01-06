#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 1000001
#define vi vector<int>
#define pb push_back
using namespace std;
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	int k;
	cin >> k >> n;
	int arr[k][n] = {0};
	priority_queue < int, vi, greater<int>>pq;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			pq.push(arr[i][j]);
		}
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}







	return 0;
}