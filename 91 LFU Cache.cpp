#include <bits/stdc++.h> 
class LFUCache {
private:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mapp; //key -> address of list of vector{key, value, freq}
    map<int, list<vector<int>>> freq; //freq -> list of vector{key, value, freq}
    
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mapp[key]);
        
        int value = vec[1];
        
        int f     = vec[2];
        
        freq[f].erase(mapp[key]);
        
        if(freq[f].empty())
            freq.erase(f);
        
        f++;
        
        freq[f].push_front(vector<int>({key, value, f}));
        
        mapp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mapp.find(key) == mapp.end())
            return -1;
        
        auto &vec = (*(mapp[key]));
        
        int value = vec[1];
        
        makeMostFrequentlyUsed(key);
        
        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        
        if(mapp.find(key) != mapp.end()) {
            auto &vec = (*(mapp[key]));
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if(size < cap) {
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mapp[key] = freq[1].begin();
        }
        else { //Time to remove LFU or LRU if tie
            
            auto &kaun_sa_list = freq.begin()->second;
            
            int key_delete = (kaun_sa_list.back())[0]; //ordered_map ensures that the begin() will be th eleast frequency
            
            kaun_sa_list.pop_back();
            
            if(kaun_sa_list.empty())
                freq.erase(freq.begin()->first);
            
            freq[1].push_front(vector<int>({key, value, 1}));
            
            mapp.erase(key_delete);
            mapp[key] = freq[1].begin();
        }
    }
};