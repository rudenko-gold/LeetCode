// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int readDoneCnt = 0;
        
        for (int i = 0; i < n; i += 4) {
            int readDone = read4(buf + i);
            readDoneCnt += readDone;
            if (readDone < 4) {
                break;
            }
        }
        if (readDoneCnt > n) {
            buf[n] = '\0';
            readDoneCnt = n;
        }
        
        return readDoneCnt;
    }
};
