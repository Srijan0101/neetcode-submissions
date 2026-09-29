class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int value){

        this->key = key;
        this->val = value;
        this->next = nullptr;
        this->prev = nullptr;
    }

};

class LRUCache {

private:
    unordered_map<int, Node*> cache;
    Node* right;
    Node* left;
    int cap;

    void remove(Node* node){

        Node* prev_node = node->prev;
        Node* next_node = node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    void insert(Node* node){

        Node* prev_node = right->prev;
        prev_node->next = node;
        node->prev = prev_node;
        node->next = right;
        right->prev = node;
    }

public:

    LRUCache(int capacity) {
        
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {

        // return value from map if key exist, also add key to most recently used
        // if value doesn't exist, return -1

        if(cache.find(key)!=cache.end()) {
            
            Node* node = cache[key];
            remove(node);
            insert(node);

            return node->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        // if key exist in map, update the value and also add the node to most recebtly used
        // if key doesn't exist, add the node to most recently and also the keu in the map
        // if capacity reaches max, remove the least recently used

        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
