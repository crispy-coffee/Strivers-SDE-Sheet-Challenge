#include<bits/stdc++.h>

class LRUCache
{
public:
    list<int> dll;
    map<int,pair<list<int>::iterator,int>> m;
    int cap = 0;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    void makerecentkey(int key){
        dll.erase(m[key].first);
        dll.push_front(key);
        m[key].first = dll.begin();
    }

    int get(int key)
    {
        // Write your code here
        if(m.find(key) == m.end())
            return -1;
        
        makerecentkey(key);
        return m[key].second;

    }

    void put(int key, int value)
    {
        // Write your code here
        if(m.find(key) != m.end()){
            m[key].second = value;
            makerecentkey(key);
        }else{
            dll.push_front(key);
            m[key] = {dll.begin(), value};
            cap--;
        }

        if(cap<0){
            int chumtiyakey = dll.back();
            m.erase(chumtiyakey);
            dll.pop_back();
            cap++;
        }

    }
};
