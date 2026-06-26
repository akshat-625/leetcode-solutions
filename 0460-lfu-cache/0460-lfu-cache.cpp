class LFUCache {
    int i=0, cap=0;
    unordered_map<int, vector<int>> m2;
    map<pair<int, int>, int> m1;
public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if (m2.find(key)==m2.end()) return -1;
        int val=m2[key][0];
        m2[key][1]++;
        m2[key][2]=i;
        i++;
        return val;
    }
    
    void put(int key, int value) {
        if (m2.find(key)==m2.end() && m1.size()==cap){
            while(true){
                auto x=*m1.begin();
                int f1=x.first.first, i1=x.first.second, k=x.second;
                int f2=m2[k][1], i2=m2[k][2];
                if ((f1!=f2)||(i1!=i2)){
                    m1.erase(m1.begin());
                    m1[{f2, i2}]=k;
                }
                else{
                    int k=(*m1.begin()).second;
                    m2.erase(k);
                    m1.erase(m1.begin());
                    break;
                }
            }
        }
        if (m2.find(key)!=m2.end()){
            m2[key]={value, m2[key][1]+1, i};
            i++;
        }
        else{
            m2[key]={value, 1, i};
            m1[{1, i}]=key;
            i++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */