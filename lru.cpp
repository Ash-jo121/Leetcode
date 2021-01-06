class LRUCache {
public:
	map<int, map<int, int> > mp;
	vector<int>v;
	int cnt = 0;
	int bcnt = 0;
	int vectorCapacity;
	LRUCache(int capacity) {
		vectorCapacity = capacity;

	}

	int get(int key) {
		if (mp.find(key) != mp.end() && mp[key]->second != -1) {
			v.remove(v.begin() + mp[key]->second)
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (mp.find(key) != mp.end()) {
			v.push_back(key);
			mp->first = key;
			mp[key]->first = value;
			mp[key]->second = cnt;
			cnt++;
			auto itr = v.begin();
			mp[*itr]->second = -1;
			v.remove(v.begin());
		}
		else {
			mp[key]->first = value;
			if (mp[key]->second != -1) {
				v.remove(v.begin() + mp[key]->second);
				v.push_back(key);
				mp[key]->second = v.end()
				                  cnt++;
				auto itr = v.begin();
				mp[*itr]->second = -1;
				v.remove(v.begin());
			}
			else {
				v.push_back(key);
				mp[key]->second = cnt;
				cnt++;
				auto itr = v.begin();
				mp[*itr]->second = -1;
				v.remove(v.begin());
			}
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int pwaram_1 = obj->get(key);
 * obj->put(key,value);
 */