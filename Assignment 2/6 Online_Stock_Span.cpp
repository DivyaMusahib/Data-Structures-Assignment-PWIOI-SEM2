// https://leetcode.com/problems/online-stock-span/submissions/1340746197

class StockSpanner {
public:
    StockSpanner() {
        
    }
    vector<pair<int,int>> arr;
    int next(int price) {
        int ans = 1;
        while(!arr.empty() and price>=arr.back().first){
            ans+=arr.back().second, arr.pop_back();
        }
        arr.push_back({price,ans});
        return arr.back().second;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */