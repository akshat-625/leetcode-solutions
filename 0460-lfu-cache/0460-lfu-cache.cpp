class Node{
    public:
        int key,val,freq;
        Node *next,*prev;

        Node(int k,int v){
            key=k;
            val=v;
            freq=1;
            next=prev=NULL;
        }
};

class List{
    public:
        int size;
        Node *head,*tail;

        List(){
            size=0;
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
        }

        void addFront(Node* node){
            Node* temp=head->next;
            head->next=node;
            node->prev=head;
            temp->prev=node;
            node->next=temp;

            size++;
        }

        void remvoveNode(Node* node){
            Node* delprev=node->prev;
            Node* delnext=node->next;
            delprev->next=delnext;
            delnext->prev=delprev;
            size--;
        }

};


class LFUCache {
public:
    int capacity;
    int cursize;
    int minFreq;
    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*>freqList;

    LFUCache(int capacity) {
        this->capacity=capacity;
        cursize=0;
        minFreq=0;
    }

    void update(Node* node){
        keyNode.erase(node->key);
        freqList[node->freq]->remvoveNode(node);
        if(node->freq==minFreq && freqList[node->freq]->size==0) minFreq++;

        node->freq++;
        if(freqList.find(node->freq)==freqList.end()) freqList[node->freq]=new List();

        freqList[node->freq]->addFront(node);
        keyNode[node->key]=node;

    }
    
    int get(int key) {
        if(keyNode.find(key)==keyNode.end()) return -1;
        Node* node=keyNode[key];
        update(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity==0) return ;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->val=value;
            update(node);
            return;
        }
        if(cursize==capacity){
            List* list=freqList[minFreq];
            Node* node=list->tail->prev;
            keyNode.erase(node->key);
            list->remvoveNode(node);
            cursize--;
        }
        cursize++;
        minFreq=1;
        Node* node=new Node(key,value);
        if(freqList.find(1)==freqList.end())freqList[1]=new List();

        freqList[1]->addFront(node);
        keyNode[key]=node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */