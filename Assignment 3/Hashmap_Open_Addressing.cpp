#include <bits/stdc++.h>
using namespace std;

class HashMapOpen {
    vector<pair<int, int>> table;
    vector<bool> occupied;
    int capacity;
    
    int hash(int key) {
        return key % capacity;
    }

public:
    HashMapOpen(int cap = 100) : capacity(cap) {
        table.resize(capacity, {0, 0});
        occupied.resize(capacity, false);
    }

    bool find(int key) {
        int index = hash(key);
        for (int i = 0; i < capacity; ++i) {
            int idx = (index + i) % capacity;
            if (!occupied[idx]) return false;
            if (table[idx].first == key) return true;
        }
        return false;
    }

    void insert(int key, int value) {
        int index = hash(key);
        for (int i = 0; i < capacity; ++i) {
            int idx = (index + i) % capacity;
            if (!occupied[idx] || table[idx].first == key) {
                table[idx] = {key, value};
                occupied[idx] = true;
                return;
            }
        }
    }

    void remove(int key) {
        int index = hash(key);
        for (int i = 0; i < capacity; ++i) {
            int idx = (index + i) % capacity;
            if (!occupied[idx]) return;
            if (table[idx].first == key) {
                occupied[idx] = false;
                return;
            }
        }
    }
};

int main() {
    HashMapOpen hm;
    hm.insert(1, 10);
    hm.insert(2, 20);
    cout << hm.find(1) << endl;  // 1
    cout << hm.find(3) << endl;  // 0
    hm.remove(1);
    cout << hm.find(1) << endl;  // 0
    return 0;
}
