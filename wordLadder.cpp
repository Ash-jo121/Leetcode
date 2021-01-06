class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		set<string>words;
		bool isPresent = false;
		for (auto itr : wordList) {
			if (endWord.compare(itr) == 0) {
				isPresent = true;
			}
			words.insert(itr);
		}

		if (isPresent == false) {
			return 0;
		}

		queue<string> q;
		int depth = 0;
		int lSize = 0;
		q.push(beginWord);

		while (!q.empty()) {
			depth = depth + 1;
			lSize = q.size();
			while (lSize--) {
				string curr = q.front();
				q.pop();
				for (int i = 0; i < curr.length(); i++) {
					string temp = curr;
					for (char l = 'a'; l <= 'z'; l++) {
						temp[i] = l;
						if (curr.compare(temp) == 0) {
							continue;
						}
						if (words.find(temp) != words.end()) {
							q.push(temp);
							words.erase(temp);
						}
						if (endWord.compare(temp) == 0) {
							return depth + 1;
						}

					}
				}
			}
		}
		return 0;

	}
};