// https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/1339614887

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    map<int,int>mp;
    vector<int>arr;
  
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            arr.push_back(val);
            mp[val]=arr.size()-1;
            }
        else return false;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            mp[arr.back()]=mp[val];
            swap(arr.back(),arr[mp[val]]);
            arr.pop_back();
            mp.erase(val);
        }
        else return false;
        return true;
    }
    
    int getRandom() {
        return arr[rand()%mp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */