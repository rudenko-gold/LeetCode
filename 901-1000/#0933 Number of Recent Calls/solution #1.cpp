class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push_back(t);
        return pings.end() - lower_bound(pings.begin(), pings.end(), t - 3000);
    }
    
    vector<int> pings;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
