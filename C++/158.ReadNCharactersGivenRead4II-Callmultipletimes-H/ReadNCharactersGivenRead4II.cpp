// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char temp[4];
    int curIndex = 4;
    int curLen = 4;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while(i<n && curLen>0){
            if(curIndex==curLen){
                curLen = read4(temp);
                curIndex = 0;
            }
            else{
                buf[i++] = temp[curIndex++];
            }
        }
        return i;
    }
};

//The API: int read4(char *buf), it reads 4 characters at a time from a file to memory. For example, the file is "absdef", we first call read4, and get "abcd", we second call read4, we get "ef";

//The implementation read is a similar function, but this time the user can decide the number of characters they need. If we have an API read1, then the process will be very simple. But we only have read4, so here is the problem. 

//So in function read, we need a pointer, and a buffer. The pointer also point to the next character is to be read, and the buffer stores the characters that has been read from the file to momery using read4
