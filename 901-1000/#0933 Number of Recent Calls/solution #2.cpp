class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push(t);
        
        while (pings.front() < t - 3000) {
            pings.pop();
        }
        
        return pings.size();
    }
    
    queue<int> pings;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
