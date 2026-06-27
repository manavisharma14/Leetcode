class LRUCache {
private:
    int cap;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>>cache;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){ return -1; }

        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto it = mp[key];
            cache.erase(it);
        } 

        cache.push_front({key, value});
        mp[key] = cache.begin();

        if(cache.size() > cap){
            int lrukey = cache.back().first;
            mp.erase(lrukey);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */