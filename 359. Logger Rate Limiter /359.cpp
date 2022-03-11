#include <string>
#include <unordered_map>
using namespace std;

class Logger {
    /*
        Title: 359. Logger Rate Limiter
        Time Complexity:
            1. shouldPrintMessage: O(1)-time

        Algorithm: 
            1. hashmap(C++ built-in unordered_map)

        Date: 12/17/2021 17:01					
        Time: 64ms  -- beat 90.53%
        Memory: 32.3 MB  -- beat 98.74%
    */
public:
    Logger() {
        log.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (log.count(message) == 0) {
            log[message] = timestamp;
            return true;
        
        } else {
            if (timestamp >= log[message] + 10) {
                log[message] = timestamp;
                return true;
            } else 
                return false;
        }
    }

private:
    unordered_map<string, int> log;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */