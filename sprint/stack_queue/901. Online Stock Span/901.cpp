class StockSpanner {
public:
    StockSpanner() {
        this -> nextId = 0;
    }
    
    int next(int price) {
        while (!st.empty() && price >= prices[st.top()]) {
            st.pop();  
        }
        int span = (st.empty()) ? (nextId + 1) : (nextId - st.top());
        
        st.push(nextId);
        prices.push_back(price);
        nextId += 1;
        return span;        
    }
    
private:
    vector<int> prices;
    stack<int> st;
    int nextId;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */