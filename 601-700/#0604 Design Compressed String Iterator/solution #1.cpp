class StringIterator {
public:
    StringIterator(string compressedString) {
        stringstream ss(compressedString);
        
        while (!ss.eof()) {
            int cnt;
            char c;
            ss >> c >> cnt;
            data.push({ c, cnt });
        }
    }
    
    char next() {
        if (hasNext()) {
            char ret = data.front().first;
            data.front().second--;
            if (data.front().second == 0) {
                data.pop();
            }
            return ret;
        } else {
            return ' ';
        }
    }
    
    bool hasNext() {
        return !data.empty();
    }
    
    queue<pair<char, int>> data;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
