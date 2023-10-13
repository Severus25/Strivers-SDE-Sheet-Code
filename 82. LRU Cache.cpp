// Problem Statement:
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
// add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:
// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Problem Solution:
class Node{
    public:
    int key;
    int val;
    Node*next;
    Node*prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>m;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    int size;
    LRUCache(int capacity) {
           size=capacity;
            head->next=tail;
             tail->prev=head;
    }
    void deleteNode(Node*p){
       Node*pre=p->prev;
       Node*nex=p->next;
       pre->next=nex;
       nex->prev=pre;
    }
    void addNode(Node*newnode){
        Node*temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    int get(int key) {
        if(m.find(key)==m.end())
        return -1;
        Node*p=m[key];
        deleteNode(p);
        addNode(p);
        m[key]=head->next;
        return head->next->val;
    }
    
    void put(int key, int value) {
       if(m.find(key)!=m.end()){
            Node*c=m[key];
            deleteNode(c);
            c->val=value;
            addNode(c);
            m[key]=head->next;
        }
        else{
            if(m.size()==size){
                Node* prev=tail->prev;
                deleteNode(prev);
                Node*l=new Node(key,value);
                addNode(l);
                m.erase(prev->key);
                m[key]=head->next;
            }
            else{
                 Node*l=new Node(key,value);
                addNode(l);
                m[key]=head->next; 
            }
        }
    }
};
