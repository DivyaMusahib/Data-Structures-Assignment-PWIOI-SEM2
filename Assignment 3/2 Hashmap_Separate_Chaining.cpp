#include <bits/stdc++.h>
using namespace std;

class HashMapSeparate {
    vector<list<pair<int, int>>> table;
    int capacity;

    int hash(int key) {
        return key % capacity;
    }

public:
    HashMapSeparate(int cap = 100) : capacity(cap) {
        table.resize(capacity);
    }

    bool find(int key) {
        int index = hash(key);
        for (const auto &p : table[index]) {
            if (p.first == key) return true;
        }
        return false;
    }

    void insert(int key, int value) {
        int index = hash(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    void remove(int key) {
        int index = hash(key);
        table[index].remove_if([key](const pair<int, int> &p) {
            return p.first == key;
        });
    }
};

int main() {
    HashMapSeparate hm;
    hm.insert(1, 10);
    hm.insert(2, 20);
    cout << hm.find(1) << endl;  // 1
    cout << hm.find(3) << endl;  // 0
    hm.remove(1);
    cout << hm.find(1) << endl;  // 0
    return 0;
}
