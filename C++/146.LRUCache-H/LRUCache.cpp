//I want to use unordered_map and list to solve this proble.
//A good thing for list is that its iterator can never been invalidated by motifier, unless the item is deleted. This way, we can store the iterator in the hash map. 
//Anthor good thing is that it only cost constant time to erase an item from list, so the get and put operation can in comstant time complexity.

//In the list, I store the key, and the most recently one is in the front head. 
//In the hashmap, I use key as hash-key, and use pair<value, iterator> as hash-value.



class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    //1. In the get operation, we first check the hashmap. 
    //1.1 if the key is not exist, then return -1;
    //1.2 If exist, then we update the order in recent list, and update the list iterator in hashmap;
    int get(int key) {
        auto it = hashmap.find(key);
        if(it==hashmap.end()) return -1;
        else{
            recent.erase(it->second.second);
            recent.push_front(key);
            it->second.second = recent.begin();
            return it->second.first;
        }
    }
    
    //2. In the put opration, there are two options.
    //2.1 If the key is not exist, we just add the pair in hashmap and recent list. If out of capacity, we delete the last recent one. 
    //2.2 If the key is exist, we have to update the value, and update the recent list. 
    void put(int key, int value) {
        auto it = hashmap.find(key);
        if(it==hashmap.end()){
            recent.push_front(key);
            hashmap[key] = make_pair(value, recent.begin());
            if(recent.size()>capacity){
                hashmap.erase(recent.back());
                recent.pop_back();
            }
        }
        else{
            it->second.first = value;
            recent.erase(it->second.second);
            recent.push_front(key);
            it->second.second = recent.begin();
        }
    }
    
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> hashmap;
    list<int> recent;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
