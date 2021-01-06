class Solution {
public:
	vector<vector<string>>collection;
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
	void findLaddersHelper(int minLength, string word, string endWord, vector<string> path, set<string>words, vector<vector<string>>collection) {
		//Base Case
		if (endWord.compare(word) == 0) {
			if (path.size() == minLength) {
				collection.push_back(path);
			}
			return;
		}
		//Recursive Case
		for (int i = 0; i < word.length(); i++) {
			string temp = word;
			for (char l = 'a'; l <= 'z'; l++) {
				temp[i] = l;
				if (word.compare(temp) == 0) {
					continue;
				}
				if (words.find(temp) != words.end()) {
					words.erase(temp);
					path.push_back(temp);
					findLaddersHelper(minLength, temp, endWord, path, words, collection);
				}
			}
		}
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		int minLength = ladderLength(beginWord, endWord, wordList);
		vector<vector<string>> v;
		if (minLength == 0) {
			return v;
		}
		set<string>words;
		for (auto itr : wordList) {
			words.insert(itr);
		}
		vector<string>path;
		path.push_back(beginWord);

		findLaddersHelper(minLength, beginWord, endWord, path, words, collection);
		return collection;

	}
};