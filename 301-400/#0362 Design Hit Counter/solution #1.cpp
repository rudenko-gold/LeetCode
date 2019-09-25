class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hits.push_back(timestamp);
        lastTimeStamp = timestamp;
        fitHits();
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        lastTimeStamp = timestamp;
        fitHits();
        return hits.size();
    }
    
    void fitHits() {
        while (hits.size() > 0 && hits.front() + (5 * 60) <= lastTimeStamp) {
            hits.pop_front();
        }
    }
    
    int lastTimeStamp;
    deque<int> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
