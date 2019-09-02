// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int getArraySize(const ArrayReader& reader) {
        int l = 0;
        int r = numeric_limits<int>::max();
        
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (reader.get(mid) == 2147483647) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
    
    int search(const ArrayReader& reader, int target) {
        int sz = numeric_limits<int>::max();
        
        int l = 0;
        int r = sz;
        
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (target <= reader.get(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (reader.get(l) == target) {
            return l;
        } else {
            return -1;
        }
    }
};
