class Node{
public: 
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
private:
    int cap;
    Node* left;
    Node* right;
    unordered_map<int, Node*> cache;

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

        // if key doesn't exist, return -1
        // if key exists, return node->val and push node to right
        
        if(cache.find(key)!=cache.end()){

            Node* node = cache[key];
            remove(node);
            insert(node);

            return node->val;
        }
        return -1;
    }
    
    void put(int key, int val) {
        
        if(cache.find(key)!=cache.end()){

            remove(cache[key]);
        }

        Node* node = new Node(key, val);
        cache[key] = node;
        insert(node);

        if(cache.size()>cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

    }
};
