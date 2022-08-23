// not working

class Node {
public:
    int val;
    Node *prev, *next;
    Node(int x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

class LFUCache {
public:
    map<int, Node*> keyadd;
    map<int, vector<Node*>> freqNodes; // freq, head, tail nodes
    map<Node*, int> addfreq;
    int cap=0, freq=0, limit;
    
    LFUCache(int capacity) {
        limit = capacity;
    }
    
    int get(int key) {
        if(keyadd.find(key) == keyadd.end())
            return -1;
        else {
            Node* address = keyadd[key];
            int oldfreq = addfreq[address];
            int ans = address->val;
            addfreq[address] = oldfreq+1;
            //erase
            Node* left = address->prev;
            Node* right = address->next;
            if(left==NULL && right==NULL) {
                freqNodes.erase(key);
            }
            else if(left==NULL) {
                right->prev = NULL;
                freqNodes[oldfreq].push_back(address);
            }
            else if(right==NULL) {
                left->next = NULL;
                freqNodes[oldfreq].push_back(address);
            }
            else {
                left->next = right;
                right->prev = left;
            }
            address->next = NULL;
            address->prev = NULL;
            
            //add
            if(freqNodes.find(oldfreq+1) == freqNodes.end()) {
                freqNodes[oldfreq+1].push_back(address); //head
                freqNodes[oldfreq+1].push_back(address); //tail
            }else {
                Node* head = freqNodes[oldfreq+1][0];
                Node* tail = freqNodes[oldfreq+1][1];
                address->next = head;
                head->prev = address;
                freqNodes[oldfreq+1][0] = address;
            }
            
            if(freqNodes.find(oldfreq) == freqNodes.end())
                freq = oldfreq+1;
            return ans;
        }
    }
    
    void put(int key, int value) {
        if(keyadd.find(key) == keyadd.end()) {
            if(cap == limit) {
                Node* node = new Node(key);
                Node* head = freqNodes[freq][0];
                Node* tail = freqNodes[freq][1];
                if(head == tail) {
                    keyadd.erase(head->val);
                    freqNodes.erase(freq);
                    freqNodes[1] = {node,node};
                    keyadd[key] = node;
                    addfreq.erase(head);
                    addfreq[node] = 1;
                }
                else {
                    tail->prev->next = NULL;
                    Node* tailprev = tail->prev;
                    int data = tail->val;
                    keyadd.erase(data);
                    addfreq.erase(tail);
                    
                    keyadd[key] = node;
                    head->prev = node;
                    node->next = head;
                    freqNodes[1] = {node,tailprev};
                    addfreq[node] = 1;
                }
            }
            else {
                Node* address = new Node(value);
                keyadd[key] = address;
                addfreq[address] = 1;
                
                if(freqNodes.find(1) == freqNodes.end()) {
                    freqNodes[1].push_back(address);
                    freqNodes[1].push_back(address);
                }
                else {
                    Node *head = freqNodes[1][0];
                    Node *tail = freqNodes[1][1];
                    address->next = head;
                    head->prev = address;
                    freqNodes[1][0] = address;
                }
                cap++;
            }
        }
        else {
            Node* node = new Node(value);
            Node* address = keyadd[key];
            keyadd[key] = node;
            
            int oldfreq = addfreq[address];
            addfreq[address] = oldfreq+1;
            
            //erase
            Node* left = address->prev;
            Node* right = address->next;
            if(left==NULL && right==NULL) {
                freqNodes.erase(key);
            }
            else if(left==NULL) {
                right->prev = NULL;
            }
            else if(right==NULL) {
                left->next = NULL;
            }
            else {
                left->next = right;
                right->prev = left;
            }
            
            //add
            if(freqNodes.find(oldfreq+1) == freqNodes.end()) {
                freqNodes[oldfreq+1].push_back(address); //head
                freqNodes[oldfreq+1].push_back(address); //tail
            }else {
                Node* head = freqNodes[oldfreq+1][0];
                Node* tail = freqNodes[oldfreq+1][1];
                address->next = head;
                head->prev = address;
                freqNodes[oldfreq+1][0] = address;
            }
        }
        freq=1;
    }
};
