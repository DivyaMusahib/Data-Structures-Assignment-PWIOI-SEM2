// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/submissions/1339627663

class RandomizedCollection
{
public:
    vector<int> arr;
    unordered_map<int, int> ump;
    RandomizedCollection(){}

    bool insert(int val){
        if (ump[val] == 0){
            arr.push_back(val);
            ump[val]++;
            return true;
        }
        else if (ump[val] > 0){
            arr.push_back(val);
            ump[val]++;
            return false;
        }
        return false;
    }

    bool remove(int val){
        if (ump[val] > 0){
            auto it = find(arr.begin(), arr.end(), val);
            arr.erase(it);
            ump[val]--;
            return true;
        }
        return false;
    }

    int getRandom(){
        return arr[rand() % arr.size()];
    }
};